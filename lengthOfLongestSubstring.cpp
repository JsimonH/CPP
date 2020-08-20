/* 无重复字符的最长字串
Given a string, find the length of the longest substring without repeating characters.

Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
*/

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int len = 0, res = 0;
        
        while(right < s.size()) {
            char curr = s[right];
            for(int i = left; i < right; ++i) {
                if(curr == s[i]) {
                    left = i + 1;
                    len = right - left;
                }
            }
            ++right;
            ++len;
            res = max(len, res);
        }
        return res;
    }
};

/* 哈希优化 */
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int len = 0, res = 0;
        unordered_map<char, int> um;

        while(right < s.size()) {
            char curr = s[right];
            if(um.find(curr) != um.end() && um[curr] >= left) {
                left = um[curr] + 1;
                len = right - left;
            }
            um[curr] = right;
            
            ++right;
            ++len;
            res = max(len, res);
        }
        return res;
    }
};
