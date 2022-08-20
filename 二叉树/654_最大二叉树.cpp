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
    int findMaxId(vector<int>& nums, int l, int r) {
        int max = -1;
        int maxId;
        for (int i = l; i <= r; ++i) {
            if (nums[i] > max) {
                max = nums[i];
                maxId = i;
            }
        }
        return maxId;
    }
    TreeNode* traversal(int l, int r, vector<int>& nums) {
        //终止条件：只剩一个节点，直接将其返回
        if (l > r) return nullptr;
        if (l == r) return new TreeNode(nums[l]);
        //找到最大值的索引以及值，建立子树根节点
        int rootId = findMaxId(nums, l, r);
        TreeNode* node = new TreeNode(nums[rootId]);
        //分割左右子树:左闭右闭区间
        //if (l <= rootId-1)
            node->left = traversal(l, rootId-1, nums);
        //if (rootId+1 <= r)
            node->right = traversal(rootId+1, r, nums);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //递归参数的返回值与参数
        return traversal(0, nums.size()-1, nums);

    }
};