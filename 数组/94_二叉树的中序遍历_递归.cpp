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
    void pre_tr(TreeNode* node, vector<int> &ivec){
        if(!node) return;

        pre_tr(node->left, ivec);
        ivec.push_back(node->val);        
        pre_tr(node->right, ivec);
    }
        
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> rec;
        pre_tr(root, rec);
        return rec;        
    }
};