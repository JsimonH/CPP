/* 字符集合
输入一个字符串，求出该字符串包含的字符集合

输入
abcqweracb
输出
abcqwer
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string str;
	  while(cin >> str)
    {
        int count[256] = { 0 };
	      for (auto ch : str)
	      {
		        if (count[ch] == 0)
		        {
			          cout << ch;
			          count[ch] = 1;
		        }
	      }
        cout << endl;
    }
    return 0;
}
