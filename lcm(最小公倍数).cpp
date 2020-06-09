/* 求最小公倍数
正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
输入两个正整数A和B。
输出A和B的最小公倍数。
*/

#include<iostream>
using namespace std;

int func(int a, int b)
{
    while(a != b)
    {
        if(a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main()
{
    int A, B;
    cin >> A >> B;
    int C = func(A, B);  // C为A和B的最大公约数
    // 最小公倍数 = AB乘积/最大公约数
    int res = A*B/C;
    cout << res << endl; 
    return 0;
}
