/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void dfs(Node *root){
        if(!root) return;
        for(auto it:root->children){
            dfs(it);
        }
        ans.emplace_back(root->val);
        return ;
    }

    vector<int> postorder(Node* root) {
        dfs(root);
        return ans;
    }

private:
    vector<int> ans;
};