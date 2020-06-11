/* 密码强度问题
密码按如下规则进行计分，并根据不同的得分为密码进行安全等级划分。

一、密码长度:

5 分: 小于等于4 个字符

10 分: 5 到7 字符

25 分: 大于等于8 个字符

二、字母:

0 分: 没有字母

10 分: 全都是小（大）写字母

20 分: 大小写混合字母

三、数字:

0 分: 没有数字

10 分: 1 个数字

20 分: 大于1 个数字

四、符号:

0 分: 没有符号

10 分: 1 个符号

25 分: 大于1 个符号

五、奖励:

2 分: 字母和数字

3 分: 字母、数字和符号

5 分: 大小写字母、数字和符号

最后的评分标准:

>= 90: 非常安全

>= 80: 安全（Secure）

>= 70: 非常强

>= 60: 强（Strong）

>= 50: 一般（Average）

>= 25: 弱（Weak）

>= 0:  非常弱


对应输出为：

VERY_SECURE

SECURE,

VERY_STRONG,

STRONG,

AVERAGE,

WEAK,

VERY_WEAK,


请根据输入的密码字符串，进行安全评定。

注：

字母：a-z, A-Z

数字：-9

符号包含如下： (ASCII码表可以在UltraEdit的菜单view->ASCII Table查看)

!"#$%&'()*+,-./     (ASCII码：x21~0x2F)

:;<=>?@             (ASCII<=><=><=><=><=>码：x3A~0x40)

[\]^_`              (ASCII码：x5B~0x60)

{|}~                (ASCII码：x7B~0x7E)
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while(cin >> str)
    {
        int score = 0;
        int	length = str.size();
	    if (length <= 4)
		    score += 5;
	    else if (length >= 5 && length <= 7)
		    score += 10;
	    else if (length >= 8)
		    score += 25;

	int	lower = 0, upper = 0;
	int digital = 0;
	int symbol = 0;
	for (int i = 0; i<length; i++)    
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			lower++;
		if (str[i] >= 'A' && str[i] <= 'Z')
			upper++;
		if (str[i] >= '0' && str[i] <= '9')
			digital++;
		if ((str[i] >= 0x21 && str[i] <= 0x2F) 
			||(str[i] >= 0x3A && str[i] <= 0x40) 
			||(str[i] >= 0x5B && str[i] <= 0x60) 
			||(str[i] >= 0x7B && str[i] <= 0x7E))
			symbol++;
	}
	if (lower == 0 && upper == 0) 
		score += 0;
	else if ((lower != 0 && upper == 0) || (lower == 0 && upper != 0))
		score += 10;
	else if (lower != 0 && upper != 0)
		score += 20;

	if (digital == 0)       
		score += 0;
	else if (digital == 1)
		score += 10;
	else if (digital>1)
		score += 20;

	if (symbol == 0)       
		score += 0;
	else if (symbol == 1)
		score += 10;
	else if (symbol>1)
		score += 25;

	if ((lower != 0 && upper != 0) && digital != 0 && symbol != 0)
		score += 5;
	else if (((lower != 0 && upper == 0) || (lower == 0 && upper != 0)) && digital != 0 && symbol != 0)
		score += 3;
	else if (symbol == 0 && digital != 0 &&
		((lower != 0 && upper == 0) || (lower == 0 && upper != 0)))
		score += 2;

	if (score >= 90)
		cout << "VERY_SECURE" << endl;
	else if (score >= 80)
		cout << "SECURE" << endl;
	else if (score >= 70)
		cout << "VERY_STRONG" << endl;
	else if (score >= 60)
		cout << "STRONG" << endl;
	else if (score >= 50)
		cout << "AVERAGE" << endl;
	else if (score >= 25)
		cout << "WEAK" << endl;
	else
		cout << "VERY_WEAK" << endl;
    }
	return 0;
}
