/* 回文排列
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. 
A permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.


Example1:
Input: "tactcoa"
Output: true（permutations: "tacocat"、"atcocta", etc.）
*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> um;
        for(auto c : s)
            um[c]++;
        
        int cnt=0;
        for(auto m : um) {
            if(m.second % 2)
                cnt++;
            if(cnt > 1)
                return false;
        }
        return true;
    }
};
