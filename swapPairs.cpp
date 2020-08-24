/* 两两交换链表中的节点
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:
Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
 // 非递归
class Solution1 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pos = dummy;
        while(head && head->next) {
            ListNode* first = head;
            ListNode* second = head -> next;
            pos -> next = second;
            first -> next = second -> next;
            second -> next = first;
            pos = first;
            head = first -> next;
        }
        return dummy->next;
    }
};

// 递归
class Solution2 {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* first = head;
        ListNode* second = head->next;
        first->next = swapPairs(second->next);
        second->next = first;
        return second;
    }
};
