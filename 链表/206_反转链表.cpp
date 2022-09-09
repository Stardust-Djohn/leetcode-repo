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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre_p = nullptr;
        ListNode* cur_p = head;
        ListNode* next_p = nullptr;
        while(cur_p){
            //next_p用来标记cur_p的后继
            next_p = cur_p->next;
            //变换指向反转链表
            cur_p->next = pre_p;
            //更改pre,cur位置
            pre_p = cur_p;
            cur_p = next_p;

        }
        return pre_p;//注意返回的指针
        
    }
};