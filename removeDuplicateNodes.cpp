/* 移除重复节点
Write code to remove duplicates from an unsorted linked list.

Example1:
Input: [1, 2, 3, 3, 2, 1]
Output: [1, 2, 3]

Example2:
Input: [1, 1, 1, 1, 2]
Output: [1, 2]
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
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_set<int> set; 
        ListNode* cur = head; 
        while(cur && cur->next) {
            set.insert(cur->val);
            if(set.count(cur->next->val)) 
                cur->next = cur->next->next;  //找到相同元素，则删除链表
            else 
                cur = cur->next; 
        }
        return head;
    }
};
