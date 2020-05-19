/*Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of 
  the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal 
  to k characters, then reverse the first k characters and left the other as original.

Input: s = "abcdefg", k = 2
Output: "bacdfeg"
*/

class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        int step = 2 * k;
        //以2k作为递进单位
        for (int i = 0; i < len; i += step)
        {
            if (i + k < len)
                reverse(s.begin() + i, s.begin() + i + k);  
            else
                reverse(s.begin() + i, s.end()); 
        }
        return s;
    }
};
