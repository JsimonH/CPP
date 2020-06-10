/* 
请编写一个函数，计算n*m的棋盘格子（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角走到右下角，总共有多少种走法，
要求不能走回头路，即：只能往右和向下走，不能往左和往上走。*/

#include<iostream>
using namespace std;

int pathSum(int n, int m)
{
	if (n == 0 || m == 0)
		return 1;
	else
		return pathSum(n - 1, m) + pathSum(n, m - 1);
}

int main()
{
    int n, m;
	  while(cin >> n >> m)
    {
        int res = pathSum(n, m);
        cout << res << endl;
    }
	  return 0;
}
