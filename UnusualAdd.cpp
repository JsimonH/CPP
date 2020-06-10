/* 另类加法
请编写一个函数，将两个数字相加。不得使用+或其他算数运算符。
给定两个int A和B。请返回A＋B的值*/

class UnusualAdd {
public:
    int addAB(int A, int B) {
        while(B)
        {
            int sum = A^B;
            int carry = (A&B)<<1; //进位值
            B = carry; //进位值给B
            A = sum; //不考虑进位值的和给A
        }
        //当进位值为0时,结果就是A
        return A;
    }
};
