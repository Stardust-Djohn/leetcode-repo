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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode dum(0);
        ListNode* head = &dum;
        ListNode* cur = head;
        //add each digit, pay attention to if carry
        while(l1 || l2){
            int num1 = (l1) ? l1->val : 0;
            int num2 = (l2) ? l2->val : 0;
            cur->next = new ListNode((num1+num2+carry)%10);
            carry = ((num1+num2+carry) >= 10) ? 1 : 0;// if carray
            //check and move to next
            cur = cur->next;
            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }
        
        //if highest digits will carry
        if(carry == 1){
            cur->next = new ListNode(1);
            cur = cur->next;
        }
        
        return head->next;
        
    // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    //     int sum = 0;
    //     int times = 0;
    //     //.*1+.*10+.*100...for the ones place, the tens place, the hundred place...
    //     while(l1 && l2){
    //         int digit = 1;
    //         for(int i = 0; i < times; ++i){
    //             digit *= 10;
    //         }
    //         sum += digit * ((l1->val)+(l2->val));
    //         l1 = l1->next;
    //         l2 = l2->next;
    //         ++times;
    //     }
    //     //rest of l1 or l2 digits
    //     ListNode* res_p = (l1) ? l1 : l2;
    //     while(res_p){
    //         int digit = 1;
    //         for(int i = 0; i < times; ++i){
    //             digit *= 10;
    //         }
    //         sum += digit * (res_p->val);
    //         res_p = res_p->next;
    //         ++times;
    //     }
    //     //get remainder by %10
    //     ListNode dum(0);
    //     ListNode* ans_head = &dum;
    //     ListNode* cur = ans_head;
    //     while(sum > 0){
    //         cur->next->val = new ListNode(sum%10);
    //         cur = cur->next;
    //         sum /= 10;
    //     }
    //     return ans_head->next;
    // }
    }        
};