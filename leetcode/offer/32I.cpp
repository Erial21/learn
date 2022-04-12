
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        //存储节点得队列
        deque<TreeNode*> que;
        //结果数组
        vector<int> res;
        //根节点放入队列
        que.push_back(root);
        if (!root) {
            return res;
        }
        while (!que.empty()) {
            int size = que.size();
            //不用i<que.size()，有可能循环时，size变化
            //当然更好的是：(i==que.size();i>0;--i)
            for (int i = 0;i < size;++i) {
                //取出队列顶部节点，遍历查找
                TreeNode* node = que.front();
                que.pop_front();
                //将值放入结果数组res
                res.push_back(node->val);
                //如果左孩子存在，则左孩子放入队列
                if (node->left) {
                    que.push_back(node->left);
                }
                //右孩子。
                if (node->right) {
                    que.push_back(node->right);
                }
            }
        }
        return res;
    }
};