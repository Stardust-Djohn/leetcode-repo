/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //确定递归参数以及返回值
        //确定终止条件
        if (root == nullptr) return root;
        //确定单层逻辑
        //当前节点在范围外，则需排除，直接返回符合的子树的根节点
        if (root->val < low) {
            return trimBST(root->right, low, high);
        }
        if (root->val > high) {
            return trimBST(root->left, low, high);
        }
        //如果符合要求则分别再去处理左、右子树并得到结果
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;

    }
};