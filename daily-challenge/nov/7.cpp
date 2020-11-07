#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/* 
l -> larger
s -> smaller
d -> difference
returns -> carry
*/
int f(ListNode* l, ListNode* s, int d) {
    if(l==nullptr || s==nullptr) return 0;
    if(d>0) {
        l->val+=f(l->next, s, d-1);
        if(l->val>9) {
            l->val-=10;
            return 1;
        }
        return 0;
    } else {
        l->val+=s->val+f(l->next, s->next, d);
        if(l->val>9) {
            l->val-=10;
            return 1;
        }
        return 0;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *l1i=l1, *l2i=l2;
    int l=0;
    while(l1i!=nullptr) {
        l1i=l1i->next;
        l++;
    }
    while(l2i!=nullptr) {
        l2i=l2i->next;
        l--;
    }
    if(l>=0) {
        l1i=l1;
        if(f(l1i, l2, l)>0)
            l1 = new ListNode(1, l1);
        return l1;
    } else {
        l2i=l2;
        if(f(l2i, l1, -l)>0)
            l2 = new ListNode(1, l2);
        return l2;
    }
}