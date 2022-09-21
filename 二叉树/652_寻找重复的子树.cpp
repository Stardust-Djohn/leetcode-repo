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
    unordered_map<string, int> ump;
    vector<TreeNode*> ans;
    string dfs(TreeNode* node) {
        if (!node) return "";
        string ss = to_string(node->val) + " " + dfs(node->left) + " " + dfs(node->right);
        ump[ss]++;
        if (ump[ss] == 2) ans.push_back(node);
        return ss;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 序列化
        // 参考：https://leetcode.cn/problems/find-duplicate-subtrees/solution/c-da-an-shun-xu-bu-zhong-yao-ha-xi-biao-7sub9/
        dfs(root);
        return ans;
    }
};