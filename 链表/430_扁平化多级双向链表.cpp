/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* cur = head;
        Node* temp = head;
        cur = flaten_list(temp);
        return head;

    }
    Node* flaten_list(Node* p){
        Node* cur = p;
        Node* pre = p;
        Node* end_list = nullptr;
        while(cur){
            if(cur->child){
                //if child node exsist,link father node to child node
                pre = cur;
                cur = cur->next;
                pre->next = pre->child;
                pre->child = nullptr;
                pre->next->prev = pre;
                //recursive to flattern child list and get the endnode
                end_list = flaten_list(pre->next);
                //link end node of flattern child list to father list
                while(cur){
                    end_list->next = cur;
                    cur->prev = end_list;
                    end_list = end_list->next;
                    cur = cur->next;
                }
                return end_list;
            }
            else{
                end_list = cur;
                cur = cur->next;
            }
        }
        //if no child node:
        return end_list;
    }
};