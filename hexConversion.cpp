/* 进制转换
给定一个十进制数M，以及需要转换的进制数N。将十进制数M转化为N进制数
输入为一行，M(32位整数)、N(2 ≤ N ≤ 16)，以空格隔开。
为每个测试实例输出转换后的数，每个输出占一行。如果N大于9，则对应的数字规则参考16进制（比如，10用A表示，等等）
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	string res, range = "0123456789ABCDEF";
	if (M == 0)
		cout << "0";
	while (M)
	{
		if (M < 0)
		{
			M = -M;
			cout << "-";
		}
		res += range[M % N];
		M /= N;
	}
	cout << res << endl;
	return 0;
}
