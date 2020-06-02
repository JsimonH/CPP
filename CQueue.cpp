/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。
(若队列中没有元素，deleteHead 操作返回 -1 )

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
*/

class CQueue {
    stack<int> st1;
    stack<int> st2;
public:
    CQueue() {}
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st2.empty())
        {
            if(st1.empty())
            {
                return -1;
            }
            else
            {
                while(!st1.empty())
                {
                    st2.push(st1.top());
                    st1.pop();
                }               
            }
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
};
