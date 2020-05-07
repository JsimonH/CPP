/* Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Input: "A man, a plan, a canal: Panama"
Output: true

Input: "race a car"
Output: false
*/

class Solution {
public:
    bool isLetterOrNumber(char ch)
    {
        return (ch >= '0' && ch <= '9')
           || (ch >= 'a' && ch <= 'z')
           || (ch >= 'A' && ch <= 'Z');
    }

    bool isPalindrome(string s) {
        // 先小写字母转换成大写，再进行判断
        for(auto& ch : s)
        {
            if(ch >= 'a' && ch <= 'z')
            ch -= 32;
        }
        
        int begin = 0, end = s.size()-1;
        while(begin < end)
        {
            while(begin < end && !isLetterOrNumber(s[begin]))
            {
                ++begin;
            }
            while(begin < end && !isLetterOrNumber(s[end]))
            {
                --end;
            }

            if(s[begin] != s[end])
            {
                return false;
            }
            else
            {
                ++begin;
                --end;
            }
        }
        return true;
    }
};
