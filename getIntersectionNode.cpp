/* 两个链表的第一个公共节点
输入两个链表，找出它们的第一个公共节点。 */

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB)
        {
            pA = pA != nullptr ? pA->next : headB;
            pB = pB != nullptr ? pB->next : headA;
        }
        return pA;
    }
};
