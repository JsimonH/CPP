/* 翻转数位
You have an integer and you can flip exactly one bit from a 0 to a 1. Write code to find the length of the longest sequence of 1s you could create.

Example 1:
Input: num = 1775(110111011112)
Output: 8

Example 2:
Input: num = 7(01112)
Output: 4
*/

class Solution {
public:
    int reverseBits(int num){
        int ans = 0;
        int cnt = 0, pre = 0;
        while(num){
            if(num & 1){
                cnt ++;
            }
            else{
                ans = max(ans, cnt + pre + 1);
                pre = cnt;
                cnt = 0;
            }
            num >>= 1;
        }
        ans = max(ans, cnt + pre + 1);
        return ans;
    }

};
