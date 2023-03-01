#include<bits/stdc++.h>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    //快慢指针
    //慢指针一次走一步，快指针一次走两步。
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head, * fast = head;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
