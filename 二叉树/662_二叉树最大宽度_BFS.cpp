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
    int widthOfBinaryTree(TreeNode* root) {
        // 每个节点宽度的关系：node：x，node->left = 2*x-1,node->right = 2*x
        // 要求出最后一层的最大/最小节点序号，相减+1为宽度
        if (!root) return 0;
        unsigned long long max_width = 1;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push(make_pair(root, 1L));
        // 层序遍历
        while (!q.empty()) {
            int sz = q.size();
            vector<pair<TreeNode *, unsigned long long>> arr;
            for (int i = 0; i < sz; ++i) {
                auto node = q.front();
                q.pop();
                arr.push_back(node);
                // 子节点入队
                if (node.first->left) q.push(make_pair(node.first->left, node.second * 2 - 1));
                if (node.first->right) q.push(make_pair(node.first->right, node.second * 2));
            }
            // 遍历完一层之后，比较最大的宽度
            max_width = max(max_width, arr.back().second - arr[0].second + 1);
        }
        return max_width;


    }
};