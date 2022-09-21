class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        //edge case
        if (head == nullptr) {
            return head;
        }
        //odd head,even head,and two pointers for threm
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        //link odd list to even list
        odd->next = evenHead;
        return head;
    }
};