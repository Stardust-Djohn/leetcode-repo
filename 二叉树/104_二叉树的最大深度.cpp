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
    int maxDepth(TreeNode* root) {
        //edge case
        if(!root) return 0;
        //botton to top
        int left_maxdep = maxDepth(root->left);
        int right_maxdep = maxDepth(root->right);
        return max(left_maxdep, right_maxdep)+1;
    }
};