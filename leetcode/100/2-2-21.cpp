// 按顺序合并两个链表
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

// 使用虚拟指针来当作新链表的头节点。
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // dummy 虚拟指针，防止
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                pre->next = list1;
                list1 = list1->next;
            } else {
                pre->next = list2;
                list2 = list2->next;
            }
            pre = pre->next;
        }

        // 剩下的节点连到末尾去。
        if (list1 != NULL) {
            pre->next = list1;
        }
        if (list2 != NULL) {
            pre->next = list2;
        }
        return dummy->next;
    }
};