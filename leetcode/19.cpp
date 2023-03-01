
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy = head;
        ListNode* left, * right;
        right = dummy;
        int i;
        for (i = 0;i < n;i++) {
            right = right->next;
        }

        left = head;

        while (right) {
            right = right->next;
            left = left->next;
        }
        left->next = left->next->next;
        ListNode* ans = dummy->next;
        return ans;
    }
};