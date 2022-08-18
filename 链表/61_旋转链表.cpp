/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        //edge case
        if(!head || !head->next) return head;
        ListNode* cur =head;
        //get the length of list
        int length = 0;
        while(cur){
            ++length;
            cur = cur->next;
        }
        //rotate数用链表长度求余数，减小操作次数
        int op_times = length-(k%length);
        if(op_times == length ) return head;//needen't operate
        //move to new head
        cur = head;//prepare pointers
        ListNode* temp = head;
        for(int i = op_times; i > 0; --i){
            temp = temp->next;
        }
        head = temp;
        //move temp to end
        while(temp->next) temp = temp->next;
        //make a new list
        temp->next = cur;//link the origin end to origin head
        while(cur->next != head) cur = cur->next;//move cur before new head
        cur->next = nullptr;
        return head;
    }
};