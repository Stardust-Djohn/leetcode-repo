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
        ivec.push_back(node->val);
        pre_tr(node->left, ivec);
        pre_tr(node->right, ivec);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> rec;
        pre_tr(root, rec);
        return rec;
    }
};
// 栈的迭代方法
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         //栈、迭代实现
//         vector<int> ret;
//         stack<TreeNode*> stk;
//         if (root) stk.push(root);
//         while (!stk.empty()) {
//             TreeNode* node = stk.top();
//             stk.pop();
//             if (node != nullptr ) {
//                 if (node->right) stk.push(node->right); //right

//                 if (node->left) stk.push(node->left);  //left

//                 stk.push(node);  //center
//                 stk.push(nullptr);
//             }
//             else {
//                 node = stk.top();
//                 ret.push_back(node->val);
//                 stk.pop();

//             }
//         }
//         return ret;
//     }
// };