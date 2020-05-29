/*  Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Note:
Division between two integers should truncate toward zero.
The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& str : tokens)
        {
            if(str == "+" || str == "-" || str == "*" || str == "/")
            {
                int rightop = st.top();
                st.pop();
                int leftop = st.top();
                st.pop();
                switch(str[0])
                {
                    case '+':
                    {
                        st.push(leftop + rightop);
                        break;
                    }
                    case '-':
                    {
                        st.push(leftop - rightop);
                        break;
                    }
                    case '*':
                    {
                        st.push(leftop * rightop);
                        break;
                    }
                    case '/':
                    {
                        st.push(leftop / rightop);
                        break;
                    }    
                }
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};
