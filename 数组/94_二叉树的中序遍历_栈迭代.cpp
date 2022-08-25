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
    vector<int> inorderTraversal(TreeNode* root) {
        //栈、迭代实现
        vector<int> ret;
        stack<TreeNode*> stk;
        if (root) stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            // 注意入栈顺序
            if (node) {
                if (node->right) stk.push(node->right);
                stk.push(node);
                stk.push(nullptr);  // 使用了nullptr针做标志，表示之后不用处理
                if (node->left) stk.push(node->left);
            }
            else {
                node = stk.top();
                ret.push_back(node->val);
                stk.pop();

            }
        }
        return ret;
    }
};