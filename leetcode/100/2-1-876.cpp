// 找到链表的中间节点

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 快慢指针，慢指针一次跳一格，快指针一次跳两格。
class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr) {
            if (fast->next->next == nullptr) {
                return slow->next;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};