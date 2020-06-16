/* 参数解析
请编写一个参数解析程序，实现将命令行各个参数解析出来。
解析规则：
参数分隔符为空格
对于用“”包含起来的参数，如果中间有空格，不能解析为多个参数。比如在命令行输入xcopy /s “C:\program files” “d:\”时，参数仍然是4个，
第3个参数应该是字符串C:\program files，而不是C:\program，注意输出参数时，需要将“”去掉，引号不存在嵌套情况。
参数不定长
输入由用例保证，不会出现不符合要求的输入
输入描述:
输入一行字符串，可以有空格

输出描述:
输出参数个数，分解后的参数，每个参数都独占一行 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str))
	{
		int count = 0; 
		int flag = 0;  //flag置为0,表示还没遇到第一个'"’
		for (int i = 0; i < str.size(); ++i)
		{
			if (str[i] == ' '&& flag == 0)   
				count++;
			if (str[i] == '"')  //遇见第一个双引号,表示在里面了,将flag置为1,表示遇见空格count不用变
			{
				flag = 1; 
			}
		}
		cout << count + 1 << endl;

		flag = 0; //没遇到 " 之前
		for (int i = 0; i < str.size(); ++i)
		{
			if (flag == 0 && str[i] != ' ') //没有遇到双引号,除了空格之外都打印
				cout << str[i];
			if (str[i] == '"') //有双引号,flag变1,下一次遇见双引号,变0
			{
				flag ^= 1;
			}
			if (flag == 1 && str[i] != '"')//在双引号里面,空格也要打印
			{
				cout << str[i];
			}
			if (str[i] == ' ' && flag == 0) // 没有遇到双引号（在双引号外面），遇到空格就换行
				cout << endl;
		}
	}
}
