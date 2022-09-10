/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //确定递归函数以及返回值
        //如果搜索到则返回，未搜索到则返回空
        //确定终止条件：遇空或者找到
        if (!root || root == p || root == q) return root;
        //单层递归逻辑:要处理完整颗树才返回
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (right && left) return root;
        if (right && !left) return right;
        else return left;
    }
};