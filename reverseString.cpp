/*
将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    // 整体倒置
    reverse(str.begin(), str.end());
    
    auto it = str.begin();
    auto start = it;
    while(it != str.end())
    {
        if(*it == ' ')
        {
            reverse(start, it);
            start = ++it;
        }
        else
            ++it;
    }
    reverse(start, it);
    cout << str << endl;
    return 0;
}
