/* 超长正整数相加
请设计一个算法完成两个超长正整数的加法。
接口说明

请设计一个算法完成两个超长正整数的加法。
输入参数：
String addend：加数
String augend：被加数
返回值：加法结果

public String AddLongInteger(String addend, String augend)
{
/在这里实现功能/

return null;
}
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string addLongInteger(const string& s1, const string& s2)
{
	string res;
	int end1 = s1.size() - 1;
	int end2 = s2.size() - 1;
	int carry = 0;
	while (end1 >= 0 || end2 >= 0)
	{
		if (end1 >= 0)
			carry += s1[end1] - '0';
		if (end2 >= 0)
			carry += s2[end2] - '0';
		res += carry % 10 + '0';
		carry /= 10;
		--end1; 
		--end2;
	}
	if (carry == 1)
		res += '1';
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	string addend, augend;
	while (cin >> addend >> augend)
	{
		 cout << addLongInteger(addend, augend) << endl;
	}
	return 0;
}
