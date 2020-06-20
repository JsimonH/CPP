/* 杨辉三角的变形

            1

         1  1  1

      1  2  3  2  1

   1  3  6  7  6  3  1

1  4  10 16 19  16 10  4  1

以上三角形的数阵，第一行只有一个数1，以下每行的每个数，是恰好是它上面的数，左上角数到右上角的数，3个数之和（如果不存在某个数，认为该数就是0）。
求第n行第一个偶数出现的位置。如果没有偶数，则输出-1。例如输入3,则输出2，输入4则输出3。 */


#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<vector<int>> vv(n, vector<int>(2 * n + 1, 0));
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < 2 * i + 1; ++j)
			{
				//第一行和第一列都为1
				if (i == 0)
					vv[i][j] = 1;
				else if (j == 0)
					vv[i][j] = 1;
				//第二列只有两个数相加
				else if (j == 1)
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				else
					vv[i][j] = vv[i - 1][j - 2] + vv[i - 1][j - 1] + vv[i - 1][j];
			}
		}

		for (int i = 0; i < 2 * n - 1; ++i)
		{
			if (vv[n - 1][i] % 2 == 0)
			{
				cout << i + 1 << endl;
				break;
			}
		}
	}
	return 0;
}
