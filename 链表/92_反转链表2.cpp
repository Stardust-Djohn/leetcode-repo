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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        //edge case
        if(!head || !head->next || left==right) return head;
        ListNode* dum=new ListNode(0,head);
        head=dum;
        ListNode* pre=dum;
        //移动到变化区域前
        for (int i = 0; i < left - 1; i++) {
            pre = pre->next;
        }
        //头插法
        ListNode *cur = pre->next;
        ListNode *next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dum->next;

    }
};