#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

/*  这个更是重量级
    递归反转链表
    不要跳进递归
    只要知道最终原本的头指针节点要变成尾节点
    只要对两个节点进行简单的置换就行了*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
};

/*  迭代的方式
    三个指针 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    while (curr) {
        struct ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
