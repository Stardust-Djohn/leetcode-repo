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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //set a dummy node
        ListNode* dummy = new ListNode(0, head);
        //two pointers , the faster one go n before the slow one
        ListNode* fast = head;
        ListNode* slow = dummy;
        for(int i = 0; i < n;++i){
            fast = fast->next;
        }
        //slow ptr go to the pos
        while(fast){
            fast = fast->next;
            slow = slow->next;
        }
        //delete
        slow->next = slow->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};