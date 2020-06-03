/*
读入一个字符串str，输出字符串str中的连续最长的数字串
input: abcd12345ed125ss123456789
output: 123456789
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str, max_digital, cur_digital;
	cin >> str;
	for (int i = 0; i <= (int)str.size(); ++i)
	{
		if (str[i] >= '0' && str[i] <= '9')
			cur_digital += str[i];
		else
		{
			if (max_digital.size() < cur_digital.size())
				max_digital = cur_digital;
			cur_digital.clear();
		}
	}
	cout << max_digital;
	return 0;
}
