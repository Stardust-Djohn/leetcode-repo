/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        //edge case
        if(!root) return nullptr;
        else{
            q.push(root);
            root->next = nullptr;
        }
        //built a queue and connect
        while(!q.empty()){
            int length = q.size();
            //for every level
            for(int i = 0; i < length; ++i){
                Node* temp_node = q.front();
                q.pop();
                //if is not leaf node, connect two son nodes
                if(temp_node->left && temp_node->right){
                    q.push(temp_node->left);
                    q.push(temp_node->right);
                    temp_node->left->next = temp_node->right;
                    //check if right node should be connect to next
                    if(temp_node->next) temp_node->right->next = temp_node->next->left;
                    else temp_node->right->next = nullptr;
                }
            }
        }
        return root;
    }
};