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
    void dfs(Node* root){
        //nullptr
        if(root==nullptr) return;
        ans.emplace_back(root->val);
        for(auto ch:root->children){
            dfs(ch);
        }
    }

    vector<int> preorder(Node* root) {
        dfs(root);
        return ans;
    }
private:
    vector<int> ans;
};