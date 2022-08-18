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
    ListNode* swapPairs(ListNode* head) {
        //base case
        if(!head || !head->next) return head;
        //swap pair
        else{
            ListNode* cur = head->next;
            head->next = cur->next;
            cur->next = head;
            head = cur;
            head->next->next = swapPairs(head->next->next);
            return head;
        }

        
    }
};