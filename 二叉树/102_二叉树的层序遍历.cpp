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
    vector<vector<int>> levelOrder(TreeNode* root) {        
        //BFS，先将每层所有的节点都遍历同时将子节点加入队列
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        //edge case        
        if(root){
           q.push(root);
        }
        else{
            return ans;
        }
        while(!q.empty()){
            int length = q.size();
            vector<int> sub_vec;
            for(int i = 0; i < length; ++i){
                auto temp_node = q.front();
                q.pop();
                sub_vec.push_back(temp_node->val);
                if(temp_node->left) q.push(temp_node->left);
                if(temp_node->right) q.push(temp_node->right);
            }
            ans.push_back(sub_vec);
        }
        return ans;
    }
};