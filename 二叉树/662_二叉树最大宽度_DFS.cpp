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
using ULL = unsigned long long;

class Solution {
public:
    // DFS遍历
    unordered_map<int, ULL> levelMin;  // 记录每一层最小的节点
    ULL traverse(TreeNode* node, int depth, ULL index) {
        if (!node) return 0LL;
        if (!levelMin.count(depth)) levelMin[depth]= index;  // 每一层最先访问到的节点会是最左边的节点，即每一层编号的最小值
        return max({index - levelMin[depth] + 1LL, traverse(node->left, depth + 1, index * 2), traverse(node->right, depth + 1, index * 2 + 1)});
    }

    int widthOfBinaryTree(TreeNode* root) {
        // function<ULL(TreeNode*, int, ULL)> dfs = [&](TreeNode* node, int depth, ULL index)->ULL {
        //     if (node == nullptr) {
        //         return 0LL;
        //     }
        //     if (!levelMin.count(depth)) {
        //         levelMin[depth] = index; 
        //     }
        //     return max({index - levelMin[depth] + 1LL, dfs(node->left, depth + 1, index * 2), dfs(node->right, depth + 1, index * 2 + 1)});
        // };
        // return dfs(root, 1, 1LL);
        return traverse(root, 1, 1LL);
        
    }
};