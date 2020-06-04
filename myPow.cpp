/* 数值的整数次方
实现函数double Power(double base, int exponent)，求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。

输入: 2.00000, 10
输出: 1024.00000

输入: 2.10000, 3
输出: 9.26100

输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25
*/

// 快速幂,时间复杂度O(logn)
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0) 
            return 1;
        double ans = 1;
        long num = n;
        if(n < 0)
        {
            num = -num;
            x = 1/x;
        }
        while(num)
        {
            if(num & 1)
            {
                ans *= x;
            }
            x *= x;
            num >>= 1;
        }
        return ans;
    }
};
