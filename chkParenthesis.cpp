/* 合法括号序列判断
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合法的括号串。

"()(()()",7
返回：false

"(()())",6
返回：true
*/

class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        if(n % 2 == 1)
            return false;
        
        stack<char> st;
        for(int i = 0; i < n; ++i)
        {
            // 遇到左括号存入栈中
            if(A[i] == '(')
                st.push(A[i]);
            // 遇到右括号,判断栈中是否有左括号.有就出栈,没有就不匹配
            else if(A[i] == ')')
            {
                if(st.empty() || st.top() != '(')
                    return false;
                else
                    st.pop();
            }
            // 其他字符返回false
            else
                return false;
        }
        // 没有匹配成功
        if(!st.empty())
            return false;
        return true;
    }
};
