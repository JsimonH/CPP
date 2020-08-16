/* 两句话中的不常见单词
We are given two sentences A and B.  (A sentence is a string of space separated words.  Each word consists only of lowercase letters.)
A word is uncommon if it appears exactly once in one of the sentences, and does not appear in the other sentence.
Return a list of all uncommon words. 
You may return the list in any order.

Example 1:
Input: A = "this apple is sweet", B = "this apple is sour"
Output: ["sweet","sour"]

Example 2:
Input: A = "apple apple", B = "banana"
Output: ["banana"]
*/

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        unordered_map<string, int> um;
        
        int start = 0, last = 0;
        string str1;
        while (last != -1) {
            last = A.find(' ', start);
            str1 = A.substr(start, last - start);
            ++um[str1];
            start = last + 1;
        } 

        start = 0, last = 0;
        string str2;
        while (last != -1) {
            last = B.find(' ', start);
            str2 = B.substr(start, last - start);
            ++um[str2];
            start = last + 1;
        }

        vector<string> res;
        for (auto& e : um) {
            if (e.second == 1) 
                res.push_back(e.first);
        }
        return res;
    }
};
