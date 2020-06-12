/* 求最大连续bit数
功能: 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1 
输入: 一个byte型的数字
返回: 对应的二进制数字中1的最大连续数*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int num;
	while (cin >> num)
	{
		vector<int> res;
		for (int i = 0; i < 32; ++i)
		{
			res.push_back((num >> i) & 1);
		}

		int cur = 0;
		int max = 0;
		for (auto e : res)
		{
			if (e == 1)
				cur++;
			else
				cur = 0;
			if (cur > max)
				max = cur;
		}
		cout << max << endl;
	}
	return 0;
}
