#include <bits/stdc++.h>

using namespace std;

// very time and space consuming, but my code
// 1364 ms, 532 MB
// class Solution {
// public:
//     vector<set<int>> A;
//     map<string, int> memo;

//     int recurssion(int i, set<int> s) {
//         if(i==A.size()) return s.size();
//         string key = to_string(i)+" ";
//         for(auto j=s.begin();j!=s.end();j++) {
//             key+=to_string(char(*j));
//         }
//         if(memo[key]!=0) return memo[key];

//         // end here
//         int end = s.size();

//         // moving ahead w/o adding these
//         int move = recurssion(i+1, s);

//         // adding, checking if it is compatable, then moving ahead
//         int beforeI=s.size();
//         int moveAndTake=0;
//         s.insert(A[i].begin(), A[i].end());
//         if(beforeI+A[i].size()==s.size())
//              moveAndTake = recurssion(i+1,s);
//         memo[key]=max<int>(end,max<int>(move,moveAndTake));
//         return memo[key];
//     }

//     int maxLength(vector<string>& arr) {
//          for(int a=0; a<arr.size(); a++) {
//              set<int> x;
//              for(int s=0; s<arr[a].length(); s++) {
//                  x.insert(int(arr[a][s]));
//              }
//              if(x.size()==arr[a].length()) A.push_back(x);
//          }
//         set<int> ans;
//         return recurssion(0,ans);
//     }
// };

// highly optimized, not my code
// 4 ms, 8.1 MB
class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        vector<bitset<26>> bits;
        for (auto s : arr)
        {
            bitset<26> a;
            for (char c : s)
                a.set(c - 'a');
            if (a.count() == s.size())
                bits.push_back(a);
        }
        return maxLength(bits, bitset<26>(), 0);
    }

    int maxLength(vector<bitset<26>> &bits, bitset<26> bs, int index)
    {
        int res = bs.count();
        for (int i = index; i < bits.size(); i++)
            if (!(bits[i] & bs).any())
                res = max(res, maxLength(bits, bs | bits[i], i + 1));

        return res;
    }
};

int main()
{
    Solution s;
    vector<string> strs{"cha", "r", "act", "ers", "un", "iq", "ue"};
    cout << s.maxLength(strs);
    return 0;
}