/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // //先遍历一遍得知长度，之后除以2，再从头遍历返回节点
        // ListNode* cur = head;
        // unsigned length = 0;
        // while(cur){
        //     ++length;
        //     cur = cur->next;
        // }
        // cur = head;
        // length /= 2;
        // while(length != 0){
        //     --length;
        //     cur = cur->next;
        // }
        // return cur;
        //快慢双指针，仅需遍历一次
        ListNode* former = head;
        ListNode* latter = head;
        while(latter && latter->next){
            former = former->next;
            latter = latter -> next -> next;
        }
        return former;
    }
};