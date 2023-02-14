#include<bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //用根节点就行
        return check(root, root);
    }
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        return (p->val == q->val) && (check(p->left, q->right) && check(p->right, q->left));
    }
};