#include <bits/stdc++.h>

using namespace std;

bool hasCycle(ListNode *head) {
    if(head==NULL) return false;
    ListNode *f=head, *s=head;
    while(f->next!=NULL && f->next->next!=NULL) {
        s=s->next;
        f=f->next->next;
        if(f==s) return true;
    }
    return false;
}