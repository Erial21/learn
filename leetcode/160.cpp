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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA, * p2 = headB;
        while (p1 != p2) {
            if (p1 == NULL) {
                //A链遍历结束，遍历B链
                p1 = headB;
            }
            else {
                p1 = p1->next;
            }
            if (p2 == NULL) {
                //B链遍历结束，遍历A链
                p2 = headA;
            }
            else {
                p2 = p2->next;
            }
        }
        return p1;
    }
};