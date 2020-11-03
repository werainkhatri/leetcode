#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    // edge case handling
    if(head==nullptr) return head;
    ListNode* sorted=head; // point the first node into a new sorted list
    head=head->next; // shift the head pointer to its next
    sorted->next=nullptr; // remove the old heads connection from the unsorted list

    while(head!=nullptr) {
        ListNode* node=head; // get the current node to place in the correct pos
        head=head->next; // increment the head pointer
        node->next=nullptr; // remove the node from the unsorted list
        if(node->val<sorted->val) { // if this is the smallest value in the sorted list
            node->next=sorted; // place it in the begining
            sorted=node;
            continue; // and move on
        }
        // else find the correct position
        ListNode* it=sorted;
        while(it->next!=nullptr) { 
            if(it->next->val>=node->val) { // if the next it node has val >= current node
                node->next=it->next; // place it after this it
                it->next=node;
                break;
            }
            it=it->next; // increment it
        }
        // if this is the largest value in the sorted list, place it at the end
        if(node->next==nullptr) it->next=node;
    }
    return sorted;
}