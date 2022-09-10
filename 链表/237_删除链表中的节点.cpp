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
    void deleteNode(ListNode* node) {
        //由于没有待删除结点的前驱结点，不能用常规的删除方法
        ListNode* next_ptr = node->next;//定义一个指向指定删除节点的后继节点的指针
        node->val = next_ptr->val;//把值复制过来
        node->next = next_ptr->next;//指定的节点直接指向后继节点的后继节点
    }
};