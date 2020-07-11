/* 查找第K小数
查找一个数组的第K小的数，注意同样大小算一样大。 如: 2 1 3 4 5 2 第三小数为3。

输入描述:
输入有多组数据。
每组输入n，然后输入n个整数(1<=n<=1000)，再输入k。

输出描述:
输出第k小的整数。

示例1
输入
6
2 1 3 5 2 2
3
输出
3
*/

#include<iostream>
#include<queue>
#include <functional> //greater仿函数
using namespace std;

int main(){
	int n;
	while (cin >> n){
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < n; ++i){
			int num;
			cin >> num;
			pq.push(num);
		}
		int k;
		cin >> k;
		int top = pq.top();
		for (int i = 0; i < k - 1; ++i){
			pq.pop();
			while (pq.top() == top){
				pq.pop();
			}
			top = pq.top();
		}
		int ret = pq.top();
		cout << ret << endl;
	}
	return 0;
}
