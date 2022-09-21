/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //edge case
        if(!head) return head;
        
        Node* cur = head;
        Node* shadow_head = nullptr;
        Node* shadow_cur = nullptr;
        //copy and insert new nodes
        while(cur){
            shadow_cur = new Node(cur->val);
            shadow_cur->next = cur->next;
            cur->next = shadow_cur;
            cur = cur->next->next;
        }
        //copy random location
        shadow_head = head->next;
        shadow_cur = shadow_head;
        cur = head;
        while(cur){
            shadow_cur->random = (cur->random) ? cur->random->next : nullptr;
            cur = cur->next->next;
            shadow_cur = (shadow_cur->next) ? shadow_cur->next->next : shadow_cur;
        }
        
        //restore
        shadow_cur = shadow_head;
        cur = head;
        while(shadow_cur->next){
            cur->next = shadow_cur->next;
            cur = shadow_cur->next;
            shadow_cur->next = cur->next;
            shadow_cur = cur->next;
        }
        //补上cur末尾的nullptr
        cur->next = nullptr;
        return shadow_head;
    }
};