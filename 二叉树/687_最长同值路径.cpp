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
    int ans = 0;
    int traverse(TreeNode* node) {
        if (!node) return 0;
        int l_len1 = 0, r_len1 = 0;
        int l_len = traverse(node->left);
        int r_len = traverse(node->right);
        if (node->left && node->left->val == node->val) l_len1 = l_len + 1;
        if (node->right && node->right->val == node->val) r_len1 = r_len + 1;
        ans = max(ans, r_len1 + l_len1);
        return max(l_len1, r_len1);
        
    }
    int longestUnivaluePath(TreeNode* root) {
        // 后序遍历
        // 判断左右、父子节点是否相同
        ans = 0;
        traverse(root);
        return ans;
    }
};