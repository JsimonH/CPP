/* 完全数计算

完全数（Perfect number），又称完美数或完备数，是一些特殊的自然数。
它所有的真因子（即除了自身以外的约数）的和（即因子函数），恰好等于它本身。
例如：28，它有约数1、2、4、7、14、28，除去它本身28外，其余5个数相加，1+2+4+7+14=28。
给定函数count(int n),用于计算n以内(含n)完全数的个数。计算范围, 0 < n <= 500000
返回n以内完全数的个数。 异常情况返回-1 */

#include<iostream>
using namespace std;

int count(int n)
{
    int count = 0;
    for(int i = 1; i <= n;++i)
    {
        int sum = 0;
        for(int j = 1; j <= i; ++j)
        {
            if(i % j == 0 && j != i)
                sum += j;
        }
        if(sum == i)
            count++;
    }
    return count;
}

int main()
{
    int n;
    while(cin >> n)
    {
        int ret = count(n);
        cout << ret << endl;
    }
    return 0;
}
