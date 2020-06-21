/* 统计每个月兔子的总数
有一只兔子，从出生后第3个月起每个月都生一只兔子，小兔子长到第三个月后每个月又生一只兔子，假如兔子都不死，问每个月的兔子总数为多少？
输入int型表示month
输出兔子总数int型
*/

#include<iostream>
using namespace std;

int rabbit(int n)
{
	int f1 = 1, f2 = 1;
	int ret = 0;
	for (int i = 3; i <= n; ++i)
	{
		ret = f1 + f2;
		f1 = f2;
		f2 = ret;
	}
	return ret;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << rabbit(n) << endl;
	}
	return 0;
}
