/*  Fibonacci数列
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，
你想让其变为一个Fibonacci数，每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
*/

#include<iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int f, f0 = 0, f1 = 1;
	int left = 0, right = 0;
	while (1)
	{
		f = f0 + f1;
		f0 = f1;
		f1 = f;

		if (f < N)
			left = N - f;
		else
		{
			right = f - N;
			break;
		}
	}
	int minStep = left < right ? left : right;
	cout << minStep << endl;
	return 0;
}
