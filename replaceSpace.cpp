/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
输入：s = "We are happy."
输出："We%20are%20happy."
*/

class Solution {
public:
    string replaceSpace(string s) {
        int size = s.size();
        int blankCount = 0;
        for(int i = 0; i < size; ++i)
        {
            if(s[i] == ' ')
                blankCount++;
        }
        int newSize = size + blankCount * 2;
        s.resize(newSize);
        int left = size;
        int right = newSize;
        while(left >= 0 && right > left)
        {
            if(s[left] == ' ')
            {
                s[right--] = '0';
                s[right--] = '2';
                s[right--] = '%';
            }
            else
            {
                s[right--] = s[left];
            }
            --left;
        }
        return s;
    }
};
