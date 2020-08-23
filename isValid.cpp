/* 有效的括号

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        if((s.size() % 2) == 1)
            return false;

        unordered_map<char, int> um = { {'(', 1}, {'[', 2}, {'{', 3}, 
                                      {')', 4}, {']', 5}, {'}', 6} };
        stack<char> st;
        for(char ch : s) {
            int val = um[ch];
            if(val >= 1 && val <= 3) 
                st.push(ch);
            else if(!st.empty() && um[st.top()] == val - 3) 
                st.pop();
            else 
                return false;
        }
        return st.empty();
    }
};
