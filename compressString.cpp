/* 字符串压缩
Implement a method to perform basic string compression using the counts of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. 
If the "compressed" string would not become smaller than the original string, your method should return the original string. You can assume the string has 
only uppercase and lowercase letters (a - z).

Example 1:
Input: "aabcccccaaa"
Output: "a2b1c5a3"

Example 2:
Input: "abbccd"
Output: "abbccd"
Explanation: 
The compressed string is "a1b2c2d1", which is longer than the original string.
*/

string compressString(string S) {
    int N = S.length();
    string res;
    int i = 0;
    while (i < N) {
        int j = i;
        while (j < N && S[j] == S[i]) {
            j++;
        }
        res += S[i];
        res += to_string(j - i);
        i = j;
    }

    if (res.length() < S.length()) {
        return res;
    } else {
        return S;
    }
}
