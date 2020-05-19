/* Given a string, you need to reverse the order of characters in each word within a sentence while still preserving 
   whitespace and initial word order.

Input: "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
In the string, each word is separated by single space and there will not be any extra space in the string.
*/

class Solution {
public:
    string reverseWords(string s) {
        string res="";
        stack<char> st;
        for(auto ch : s)
        {
            if(ch !=' ')
            {
                st.push(ch);
            }
            else
            {
                while(!st.empty())
                {
                    res += st.top();
                    st.pop();
                }
                res += ' '; 
            }
        }
        // 最后一组后面没有空格
        while(!st.empty())
        {
            res += st.top();
            st.pop();
        } 
        return res;
    }
};
