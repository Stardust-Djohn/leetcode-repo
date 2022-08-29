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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        // 原题意思是添加元素到对应的数组末尾，再构成新的树
        // 添加节点的含义参考leetcode 654
        // 向右节点遍历，如果为空或者不符合题意的，构建新的关系并返回
        if (!root || root->val < val) {
            return new TreeNode(val, root, nullptr);
        } else {
            // 其余情况，继续向右子树查找
            root->right = insertIntoMaxTree(root->right, val);
            return root;
        }

    }
};