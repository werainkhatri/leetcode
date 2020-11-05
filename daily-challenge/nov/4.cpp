#include <bits/stdc++.h>

using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& ed) {
    // lower edge cases
    if(n==1) return {0};
    if(n==2) return {0,1};
    // matrix to store the tree
    vector<list<int>> mat(n);
    // degree of each node (no of nodes this node is attached to)
    vector<int> degree(n);
    // populating mat and degree
    for(vector<int> e:ed) {
        mat[e[0]].push_back(e[1]);
        mat[e[1]].push_back(e[0]);
        degree[e[0]]++;
        degree[e[1]]++;
    }

    vector<int> leaf; // array of leaves in the tree at this point
    for(int i=0; i<n; i++) // all the nodes who
        if(degree[i]==1) // have degree as 1 are leaves
            leaf.push_back(i);
    
    // it can be easily proved that length of the output is always at most 2
    while(n>2) {
        vector<int> newleaf; // array of newly formed leaves
        int m=leaf.size();
        n-=m; // removing the leaves from the tree
        for(int i=0; i<m; i++) { // for each leaf, remove it from the tree
            int l=leaf[i]; // get the leaf
            int par=mat[l].front(); // get it's parent (the only other node it is attached to, since its degree is 1)
            for(auto p=begin(mat[par]); p!=end(mat[par]); p++) // iterate over the it's parent's adjescent nodes
                if(*p==l) { // find the this leaf
                    mat[par].erase(p); // and remove it
                    break;
                }
            degree[par]--; // reduce the degree of the parent node
            if(degree[par]==1) newleaf.push_back(par); // if this parent becomes a leaf, add it to the new leafs array
        }
        leaf=newleaf; // assign newleaf to leaf
    }
    return leaf; // finally, the remaining leaves are the answer
}