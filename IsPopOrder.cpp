/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
（注意：这两个序列的长度是相等的）
*/

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    //入栈和出栈的元素个数必须相同
    if(pushV.size() != popV.size())
        return false;
    //用s来模拟入栈与出栈的过程
    int outIdx = 0;
    int inIdx = 0;
    stack<int> s;
    while(outIdx < popV.size())
    {
        // 如果s是空，或者栈顶元素与出栈的元素不相等，就入栈
        while(s.empty() || s.top() != popV[outIdx])
        {
            if(inIdx < pushV.size())
                s.push(pushV[inIdx++]);
            else
                return false;
        }
       // 栈顶元素与出栈的元素相等，出栈
       s.pop();
       outIdx++;
    }
   return true;
  }
};
