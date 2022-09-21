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
    vector<TreeNode*> build_BST(int start, int end){
        //base case
        if(start > end) return {nullptr};
        //built root
        vector<TreeNode*> all_trees;
        for(int i = start; i <= end; ++i){
            //get all left/right son trees
            vector<TreeNode*> leftTrees = build_BST(start, i-1);
            vector<TreeNode*> rightTrees = build_BST(i+1, end);
            //link node to all son trees    
            for(auto &l : leftTrees){
                for(auto &r : rightTrees){
                    //built root
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    all_trees.emplace_back(root);
                }
            }
        }
        return all_trees;
        
    }
    
    vector<TreeNode*> generateTrees(int n) {
        //edge case
        if(n == 0) return {};
        //recursive
        return build_BST(1, n);
    }
};