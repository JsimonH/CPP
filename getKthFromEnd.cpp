/* 链表中倒数第k个节点
输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有6个节点，从头节点开始，它们的值依次是1、2、3、4、5、6。这个链表的倒数第3个节点是值为4的节点。

给定一个链表: 1->2->3->4->5, 和 k = 2.
返回链表 4->5.
*/

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        // fast指针先走k步
        for(int i = 0; i < k; ++i)
        {
            fast = fast->next;
        }
       
        // 两个指针一起走,fast到达链表末尾,slow刚好指向倒数第k个节点
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
