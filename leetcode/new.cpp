#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* SortList(ListNode* pHead) {
    ListNode* left, * right;
    ListNode* cur;
    ListNode* dummy;
    dummy->next = pHead;
    left = dummy, cur = pHead;
    right = cur->next;
    while (cur->next) {
        if ((cur->val) % 2 == 0) {
            left->next = right;
            cur = right;
            right = right->next;
        }
        else {
            left = cur;
            cur = right;
            right = right->next;
        }
        return dummy->next;
    }
}
