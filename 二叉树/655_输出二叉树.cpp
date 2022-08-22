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
    // 求二叉树深度
    int getHeight(TreeNode * node) {
        if (!node) return 0;
        int leftH = getHeight(node->left);
        int rightH = getHeight(node->right);
        return max(leftH,rightH) + 1;
    }
    void traverse(vector<vector<string>>& ans,int height,TreeNode* node, int row, int col) {
        if (!node) return;
        // 填充
        ans[row][col] = to_string(node->val);
        traverse(ans, height, node->left, row+1, col-pow(2,height-row-1)); // 左节点位置
        traverse(ans, height, node->right, row+1, col+pow(2,height-row-1)); // 右节点位置
        return ;
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root) - 1; // 获取符合题目需要的二叉树高度
        int m = height + 1, n = pow(2,height+1)-1; // 计算所需要的容器大小
        vector<vector<string>> ans(m, vector<string>(n, ""));
        traverse(ans, height, root, 0, (n-1)/2);
        return ans;
    }
};