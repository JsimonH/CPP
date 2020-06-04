/* 二进制中1的个数
请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
*/

class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n)
        {
            n &= n-1; // n与n-1进行与(&)运算,可以将n的二进制位中最低位的1变为0,直到n的二进制位全为0,即:n等于0
            count++;
        }
        return count;
    }
};

class Solution2 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 0; i < 32; ++i)
        {
            if((n>>i) & 1)
                count++;
        }
        return count;
    }
};
