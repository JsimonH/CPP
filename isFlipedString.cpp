/* 字符串轮转
Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 (e.g.,"waterbottle" is a rotation of"erbottlewat"). Can you use only one call to the method that checks if one word is a substring of another?

Example 1:
Input: s1 = "waterbottle", s2 = "erbottlewat"
Output: True

Example 2:
Input: s1 = "aa", "aba"
Output: False
*/

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        }

        string str = s1 + s1;
        if(str.find(s2) != -1) {
            return true;
        }
        return false;
    }
};
