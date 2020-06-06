/* 反转链表
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

// 双指针
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = head;
        ListNode* cur = NULL;
        while(prev)
        {
            ListNode* next = prev->next;
            prev->next = cur;
            cur = prev;
            prev =next;
        }
        return cur;
    }
};

// 递归解法
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) 
        {
            return head;
        }
        ListNode* ret = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return ret;
    }
};
