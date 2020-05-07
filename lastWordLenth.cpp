/*计算字符串最后一个单词的长度，单词以空格隔开。
input: hello world
output: 5
*/

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);  //这里不能使用cin输入,因为它遇到字符串中有空格就结束了
    size_t pos = s.rfind(' ');
    cout<< s.size()-(pos+1) << endl;
    return 0;
}
