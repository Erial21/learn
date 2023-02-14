#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;
enum CupSize {
    midium,
    large,
    super_large
};
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        //两棵树都不为空
        if (A && B) {
            return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
        }
        //记得return
        return false;
    }
    bool recur(TreeNode* A, TreeNode* B) {
        //如果B遍历完了,那么则找到相同子树,返回
        if (B == nullptr) {
            return true;
        }
        //A遍历结束或者A和B节点的值不同,返回
        if (A == nullptr || A->val != B->val) {
            return false;
        }
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};