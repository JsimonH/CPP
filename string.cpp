#include<iostream>
#include<string>
using namespace std;

int main()
{
	//string s1;// 默认构造函数
	//string s2("hello world");
	//string s3("hello world", 5);
	//string s4(s2);// 默认拷贝构造函数
	//string s5(s2, 6, 2);
	//string s6(s2, 6);
	//string s7(10, 'a');
	//
	//cout << s1 << endl;
	//cout << s2 << endl;
	//cout << s3 << endl;
	//cout << s4 << endl;
	//cout << s5 << endl;
	//cout << s6 << endl;
	//cout << s7 << endl;

	//s1 = s2;
	//cout << s1 << endl;

	/*string s1("hello world");
	cout << s1 << endl;*/

	// 访问  []+下标
	/*for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << s1[i] << " ";
	}
	cout << endl;*/

	//// 修改
	//for (size_t i = 0; i < s1.size(); ++i)
	//{
	//	s1[i] += 1;
	//}
	//cout << s1 << endl;

	// 迭代器iterator
	//string::iterator it = s1.begin();
	//while (it != s1.end())
	//{
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	//// 反向迭代器
	//string::reverse_iterator rit = s1.rbegin();
	//while (rit != s1.rend())
	//{
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;

	// 范围for
	/*for (auto ch : s1)
	{
		cout << ch << " ";
	}
	cout << endl;*/

	/*s1.reserve(10);
	s1.resize(20, 'a');
	cout << s1 << endl;*/
	string s;
	// 第一种方式
	s.push_back('1');
	s.append("2345");
	cout << s << endl;

	// 第二种方式
	s += '5';
	s += "4321";
	cout << s << endl;

	s.insert(s.begin(), '0'); // 在字符串开头插入字符'0'
	cout << s << endl;

	s.erase(2, 5);  // 从下标为2的位置开始去掉5个字符
	cout << s << endl;

	return 0;
}
