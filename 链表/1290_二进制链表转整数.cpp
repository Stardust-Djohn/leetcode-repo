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
    int getDecimalValue(ListNode* head) {
        //时间复杂度O(n)，空间复杂度O(1)
        int decimal_num = 0;
        while (head) {
            decimal_num <<= 1;
            decimal_num |= head->val;  //位运算
            head = head->next;
        }
        return decimal_num;
    }
};