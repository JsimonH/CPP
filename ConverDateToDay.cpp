/*
输入某年某月某日，判断这一天是这一年的第几天？
*/

#include<iostream>
using namespace std;

int main()
{
    static int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int year, month, day;
    //不断接收输入测试
	while (cin >> year >> month >> day)
	{
		int n = 0;
		// 累加[1,month-1]月的天数
		for (int i = 1; i < month; ++i)
		{
			n += monthDays[i];
		}
		// 累加month那个月的天数
		n += day;
		// 闰年+1天
		if (month > 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			n += 1;
		}
		cout << n << endl;
	}
	return 0;
}
