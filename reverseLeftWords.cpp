/* 剑指Offer 58-II.左旋字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：
输入: s = "abcdefg", k = 2
输出: "cdefgab"

示例 2：
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
*/

class Solution {
public:
    string reverse(string &s, int begin, int end) 
    {
        while (begin < end) 
        {
            swap(s[begin], s[end]);
            ++begin;
            --end;
        }
        return s;
    }
    string reverseLeftWords(string s, int n) {
        int len = s.size();
        if (len <= 1) 
            return s;
        
        reverse(s, 0, n - 1);
        reverse(s, n, len - 1);
        reverse(s, 0, len - 1);
        return s;
    }
};
