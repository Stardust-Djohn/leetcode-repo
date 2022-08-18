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
    bool hasCycle(ListNode *head) {
        ListNode* fast_ptr = head;
        ListNode* slow_ptr = head;
        if(head == nullptr || head->next == nullptr){//特殊情况：只有一个节点或者为空，利用或运算的短路方法
            return false;
        }
        do{//设置两个指针：一个一次前进两个节点，一个只前进一个，如果相遇（套圈）则说明是循环链表
            if(fast_ptr->next == nullptr || fast_ptr->next->next == nullptr){//先检测快指针第一步会不会越界
                return false;
            }
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            if(fast_ptr == slow_ptr){
                return true;
            }
        }
        while(true);//终止条件：相遇或者快的指针走到null
        return false;
    }
};