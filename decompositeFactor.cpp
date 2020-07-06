/* 分解因数
所谓因子分解，就是把给定的正整数a，分解成若干个素数的乘积，即 a = a1 × a2 × a3 × … × an,并且 1 < a1 ≤ a2 ≤ a3 ≤ … ≤ an。其中a1、a2、…、an均为素数。 
先给出一个整数a，请输出分解后的因子。

输入描述：
输入包含多组数据，每组数据包含一个正整数a（2≤a≤1000000）。
输出描述：
对应每组数据，以“a = a1 * a2 * a3…”的形式输出因式分解后的结果。

示例：
输入
10
18
输出
10 = 2 * 5
18 = 2 * 3 * 3
*/

// write your code here cpp
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a;
	while (cin >> a)
	{
		cout << a << " = ";
		for (int i = 2; i <= sqrt(a); ++i)
		{
			if (a % i == 0)
			{
				while (a % i == 0)
				{
					a /= i;
					cout << i;
					if (a != 1)
					{
						cout << " * ";
					}
				}
			}
		}
		if (a != 1)
			cout << a;
		cout << endl;
	}
	return 0;
}
