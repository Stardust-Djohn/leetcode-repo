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
    bool check(TreeNode* a,TreeNode* b){
        if(!a && !b) return true;
        else if(!a || !b) return false;
        return a->val==b->val && check(a->left,b->right) && check(a->right,b->left);
    }

    bool isSymmetric(TreeNode* root) {
        //镜像后遍历的结果是否一致
        return check(root,root);
        
    }

};