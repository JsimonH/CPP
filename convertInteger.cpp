/* 整数转换
Write a function to determine the number of bits you would need to flip to convert integer A to integer B.

Example1:
Input: A = 29 (0b11101), B = 15 (0b01111)
Output: 2

Example2:
Input: A = 1，B = 2
Output: 2
*/

class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int a = A, b = B;
        int count = 0;
        while(a != 0 || b != 0)
        {
            count += (a & 1) ^ (b & 1);
            a >>= 1;
            b >>= 1;
        }
        return count;
    }
};
