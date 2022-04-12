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
    vector<vector<int>> levelOrder(TreeNode* root) {
        deque<TreeNode*>que;
        vector<vector<int>> res;
        que.push_back(root);
        if (!root) {
            return res;
        }
        while (!que.empty()) {
            vector<int>tmp;
            int size = que.size();
            //不用i<que.size()，有可能循环时，size变化
            //当然更好的是：(i==que.size();i>0;--i)
            for (int i = 0;i < size;++i) {
                TreeNode* node = que.front();
                que.pop_front();
                tmp.push_back(node->val);
                if (node->left) {
                    que.push_back(node->left);
                }
                if (node->right) {
                    que.push_back(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};