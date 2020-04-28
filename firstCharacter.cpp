/*找出字符串中第一个只出现一次的字符
输入一个非空字符串,输出第一个只出现一次的字符，如果不存在输出-1
例如:
输入
asdfasdfo
输出
o
*/

#include<iostream>
using namespace std;
#include<string>

int main()
{
   string str;
   while(cin >> str)
   {
       int i = 0;
       int flag = 0;
       for (i = 0; i < str.size(); i++)
       {
         int count=0;
         for (int j = 0; j < str.size(); j++)
         {
             if (str[i] == str[j])
                 count++;
         }
           
         if (count == 1)
         {
             flag=1;
             break;
         }
       }
       
       if (flag == 0)
           cout << -1 << endl;
       else
           cout << str[i] << endl; 
   }
    return 0;
}
