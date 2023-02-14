/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//使用哈希集合，存入节点
//遍历headB来查找，第一个找到的节点就是连接节点。
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> set;
        ListNode* node1=headA;
        ListNode* node2=headB;
        while(node1){
            set.insert(node1);
            node1=node1->next;
        }
        while(node2){
            if(set.count(node2)){
                return node2;
            }
            node2=node2->next;
        }
        return NULL;
    }
};