/* 环路检测
Given a circular linked list, implement an algorithm that returns the node at the beginning of the loop.
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so as to make a loop in the linked list.

Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1

Example 2:
Input: head = [1,2], pos = 0
Output: tail connects to node index 0

Example 3:
Input: head = [1], pos = -1
Output: no cycle
*/

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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return NULL;

        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)
                break;
        }
        if(fast != slow)
            return NULL;

        fast = head;
        while(fast != slow) {
            fast=fast->next;
            slow=slow->next;
        }
        return fast;
    }
};
