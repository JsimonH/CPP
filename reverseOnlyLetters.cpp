/*Reverse Only Letters
Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, 
and all letters reverse their positions.

Input: "ab-cd"
Output: "dc-ba"

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
*/

class Solution {
public:
    bool IsChar(char ch)
    {
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    string reverseOnlyLetters(string S) {
        int begin = 0;
        int end = S.size()-1;
        while(begin < end)
        {
            while(begin < end && IsChar(S[begin]) == false)
            {
                ++begin;
            }

            while(begin < end && IsChar(S[end]) == false)
            {
                --end;
            }

            swap(S[begin], S[end]);
            ++begin;
            --end;
        }
        return S;
    }
};
