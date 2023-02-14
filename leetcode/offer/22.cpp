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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        //快慢指针，fast和slow之间相差k
        //fast先走k步，然后fast和slow同步走
        //当fast走到最后，slow就到位了。
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=1;i<k;++i){
            fast=fast->next;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;

    }
};