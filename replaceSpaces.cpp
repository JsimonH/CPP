/* 面试题 01.03. URL化
Write a method to replace all spaces in a string with '%20'. You may assume that the string has sufficient space at the end to hold the additional characters,and 
that you are given the "true" length of the string. 

Example 1:
Input: "Mr John Smith ", 13
Output: "Mr%20John%20Smith"

Example 2:
Input: "               ", 5
Output: "%20%20%20%20%20"
*/

class Solution {
public:
    string replaceSpaces(string S, int length) {
        int space = 0;
        for(int i = 0; i < length; ++i)
        {
            if(S[i] == ' ')
                space++;
        }

        int newlength = length + space * 2;
        int j = newlength - 1;
        for (int i = length - 1; i >= 0; --i) 
        {
            if (S[i] == ' ') 
            {
                S[j--] = '0';
                S[j--] = '2';
                S[j--] = '%';
            } 
            else 
                S[j--] = S[i];
        }
        S[newlength] = '\0';
        return S;
    }
};
