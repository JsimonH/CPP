/* 排序链表
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:
Input: 4->2->1->3
Output: 1->2->3->4

Example 2:
Input: -1->5->3->4->0
Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) 
            return head;
        
        ListNode* prev = head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return mergeTwoList(sortList(head), sortList(slow));
    }
    
    ListNode* mergeTwoList(ListNode* h1, ListNode* h2) {
        if(h1 == NULL) 
            return h2;
        if(h2 == NULL) 
            return h1;
        if(h1->val < h2->val) {
            h1->next = mergeTwoList(h1->next, h2);
            return h1;
        }
        else {
            h2->next = mergeTwoList(h1, h2->next);
            return h2;
        }
    }
};
