#include<bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//优先队列
class Solution {
public:
    //仿函数
    struct cmp {
        bool operator()(const ListNode* lhs, const ListNode* rhs) {
            //把优先队列改为小顶堆排序
            return lhs->val > rhs->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        //虚拟头节点
        ListNode* head = new ListNode(-1);
        ListNode* p = head;
        //把所有链表的第一个元素放入优先队列
        for (auto &node : lists) {
            if (node != NULL) {
                pq.push(node);
            }
        }
        //每次取出优先队列中最小的元素，放入链表
        while (!pq.empty()) {
            p->next = pq.top();
            p = p->next;
            pq.pop();
            //如果当前节点的下一个节点不为空，则将其加入优先队列
            if (p->next) {
                pq.push(p->next);
            }
        }
        //返回head的下一个节点
        return head->next;
    }
};