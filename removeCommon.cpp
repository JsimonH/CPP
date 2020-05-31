/* 删除公共字符
输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。例如，输入”They are students.”和”aeiou”，则删除之后的
第一个字符串变成”Thy r stdnts.”
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i = 0; i < s1.size(); ++i)
    {
        if(s2.find(s1[i]) == -1)
            cout << s1[i];
    }
    return 0;
}
