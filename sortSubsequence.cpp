/* 排序子序列
牛牛定义排序子序列为一个数组中一段连续的子序列,并且这段子序列是非递增或者非递减排序的。
牛牛有一个长度为n的整数数组A,他现在有一个任务是把数组A分为若干段排序子序列,牛牛想知道他最少可以把这个数组分为几段排序子序列.
如样例所示,牛牛可以把数组A划分为[1,2,3]和[2,2,1]两个排序子序列,至少需要划分为2个排序子序列,所以输出2。

输入
6
1 2 3 2 2 1
输出
2
*/

#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.resize(n);
	
  for(int i = 0; i < n; ++i)
		cin>>v[i];
		
	int ret = 1;
	for(int i = 1; i < n-1; ++i)
  {	
    //找出波峰波谷
		if((v[i-1] < v[i] && v[i] > v[i+1])
		  || (v[i-1] > v[i] && v[i] < v[i+1]))
    {
			ret++;
			if(i != n-3)
				i++;
    }
  }
	cout<<ret<<endl;
}
