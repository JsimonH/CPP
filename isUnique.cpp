/* 面试题 01.01.判断字符是否唯一
Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures?

Example 1:
Input: s = "leetcode"
Output: false

Example 2:
Input: s = "abc"
Output: true
*/

class Solution {
public:
    bool isUnique(string astr) {
        unordered_map<char, int> mp;
        for(int i = 0; i < astr.size(); ++i)
        {
            if(mp[astr[i]]) 
                return false;
            mp[astr[i]] ++;
        }
        return true;
    }
};
