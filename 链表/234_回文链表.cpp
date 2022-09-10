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
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *p = head;
        unsigned length;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *nex = nullptr;
        bool flag = true;
        //先求链表长度
        for (length = 0; p; ++length)
        {
            p = p->next;
        }
        if (length == 1)
        { //特殊情况：链表长度为1
            return flag;
        }
        for (int i = 0; i < length / 2; ++i)
        { //反转前一半的链表
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        if (length % 2 == 1)
        { //如果链表长度为奇数
            nex = nex->next;
        }
        while (pre && nex)
        {
            if (pre->val != nex->val)
            {
                flag = false;
                break;
            }
            pre = pre->next;
            nex = nex->next;
        }
        return flag;
    }
};

// 递归法
// class Solution {
//     ListNode* frontPointer;
// public:
//     bool recursivelyCheck(ListNode* currentNode) {
//         if (currentNode != nullptr) {
//             if (!recursivelyCheck(currentNode->next)) {
//                 return false;
//             }
//             if (currentNode->val != frontPointer->val) {
//                 return false;
//             }
//             frontPointer = frontPointer->next;
//         }
//         return true;
//     }

//     bool isPalindrome(ListNode* head) {
//         frontPointer = head;
//         return recursivelyCheck(head);
//     }
// };