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
        int count=0;
        while (!que.empty()) {
            vector<int> tmp;
            for (int i = que.size();i > 0;--i) {
                TreeNode* node;
                if (count % 2 == 0) {
                    node = que.front();
                    que.pop_front();
                    tmp.push_back(node->val);
                    if (node->left) {
                        que.push_back(node->left);
                    }
                    if (node->right) {
                        que.push_back(node->right);
                    }
                }
                else if (count % 2 == 1) {
                    node = que.back();
                    que.pop_back();
                    tmp.push_back(node->val);
                    if (node->right) {
                        que.push_front(node->right);
                    }
                    if (node->left) {
                        que.push_front(node->left);
                    }
                }
            }
            count++;
            res.push_back(tmp);
        }
        return res;
    }
};