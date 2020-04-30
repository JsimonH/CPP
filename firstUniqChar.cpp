/* First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
       
        for(auto ch : s)
        {
            count[ch - 'a']++;
        }

        for(size_t i=0; i<s.size(); ++i)
        {
            if(count[s[i]-'a'] == 1)
            {
                 return i;
            }   
        }
        return -1;
    }
};
