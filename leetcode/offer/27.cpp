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
    //孩子交换后，根节点也交换，递归到上层，就全对称了
    TreeNode* mirrorTree(TreeNode* root) {
        TreeNode* left = mirrorTree(left);
        TreeNode* right = mirrorTree(right);
        root->left = right;
        root->right = left;
        return root;
    }
};