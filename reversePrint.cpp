/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
输入：head = [1,3,2]
输出：[2,3,1]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//方法一: 栈的后进先出
class Solution1 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        stack<int> st;
        while(head)
        {
            st.push(head->val);
            head = head->next;
        }
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};

//方法二: 递归
class Solution2 {
public:
    vector<int> reversePrint(ListNode* head) {
        if(head == nullptr)
            return {};
        vector<int> res = reversePrint(head->next);
        res.push_back(head->val);
        return res;
    }
};

//方法三: reverse函数
class Solution3 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while(head)
        {
            res.push_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

//方法四: 修改链表结构
class Solution4 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while(cur)
        {
            ListNode* next = cur->next;//保存当前结点的下一个节点
            cur->next = pre;//当前结点指向前一个节点，反向改变指针
            pre = cur;//更新前一个节点
            cur = next;//更新当前结点
        }
        //pre指向新的链表头
        while(pre)
        {
            res.push_back(pre->val);
            pre = pre->next;
        }
        return res;
    }
};
