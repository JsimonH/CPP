/* 面试题 01.02. 判断是否互为字符重排
Given two strings,write a method to decide if one is a permutation of the other.

Example 1:
Input: s1 = "abc", s2 = "bca"
Output: true

Example 2:
Input: s1 = "abc", s2 = "bad"
Output: false
*/

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        unordered_map<char, int> m;
        for(int i = 0; i < s1.size(); i ++)
            m[s1[i]] ++;
        for(int i = 0; i < s2.size(); i ++)
            m[s2[i]] --;
        unordered_map<char, int>::iterator it = m.begin();
        while(it != m.end())
        {
            if(it->second != 0) 
                return false;
            ++it;
        }
        return true;
    }
};
