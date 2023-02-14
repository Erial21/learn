/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val){
            return head->next;
        }
        //双指针，一前一后，删除
        ListNode* left=head;
        ListNode* right=head->next;
        //right在前吗，判断right
        while(right!=NULL&&right->val!=val){
            left=right;
            right=right->next;
        }
        left->next=right->next;
        right=left->next;
        return head;
    }
};