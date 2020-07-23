/* 回文链表
Implement a function to check if a linked list is a palindrome.

Example 1:
Input:  1->2
Output:  false 

Example 2:
Input:  1->2->2->1
Output:  true 
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
            return true;
       
        //通过快慢指针找到中间结点
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        //通过头插法将链表前半段反转
        ListNode* p = head;
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        while(p->next != slow && p->next != NULL) {
            ListNode* r = p->next;
            p->next = r->next;
            r->next = dummyHead->next;
            dummyHead->next = r;
        }
        p = dummyHead->next;
        if(fast)//如果慢指针指向正中间的结点
            slow = slow->next;
        while(slow){//比较是否为回文
            if(slow->val != p->val)
                return false;
            slow = slow->next;
            p = p->next;
        }
        return true;
    }
};
