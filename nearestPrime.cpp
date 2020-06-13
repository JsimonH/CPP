/* 查找组成一个偶数最接近的两个素数
任意一个偶数（大于2）都可以由2个素数组成，组成偶数的2个素数有很多种情况，本题目要求输出组成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数
输出描述:
输出两个素数*/

#include<iostream>
using namespace std;

bool isPrime(int n)
{
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	int num;
	while (cin >> num)
	{
		for (int i = num / 2; i >= 2; --i)
		{
			if (isPrime(i) && isPrime(num - i))
			{
				cout << i << endl << num - i << endl;
				break;
			}
		}
	}
	return 0;
}
