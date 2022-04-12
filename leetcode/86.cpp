#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        //维护两个链表，最后把他们接起来就好了。
        //一个存小于x的，一个存大于等于x的
        //smallHead/largeHead两个指针指向创建的两个0节点
        //small和large两个指针是移动来创建新链表的
        ListNode* small = new ListNode();
        ListNode* large = new ListNode();
        ListNode* smallHead = small;
        ListNode* largeHead = large;
        while (head) {
            //判断当前head指向节点的值是否小于x
            if (head->val < x) {
                small->next = head;//往小链表放入一个节点
                //移动small指针到链表最后一个节点的位置
                small = small->next;
            }
            //大于等于x的情况
            else {
                large->next = head;//往大链表放入一个节点
                ////移动large指针到链表最后一个节点的位置
                large = large->next;
            }
            //向后移动head
            head = head->next;
        }
        //防止large->next指向一个值比x小的节点
        large->next = nullptr;
        //拼接链表
        small->next = largeHead->next;
        head = smallHead->next;
        return head;
    }
};
int main() {
    ListNode* tmp = new ListNode();
    cout << tmp->val << endl;
    return 0;
}