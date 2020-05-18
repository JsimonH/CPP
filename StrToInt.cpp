/*将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入一个字符串,包括数字字母符号,可以为空
如果是合法的数值表达则返回该数字，否则返回0
*/

class Solution {
public:
	int StrToInt(string str) {
		int res = 0, n = str.size(), flag = 1;
		if (!n)
			return 0;
		int start;
		for (start = 0; start < n; start++)
		{
			if (str[start] == '-' || str[start] == '+' || ('0' <= str[start] && str[start] <= '9'))
				break;
		}

		if (str[start] == '-')
			flag = -1;

		for (int i = (str[start] == '-' || str[start] == '+') ? start + 1 : start; i < n; ++i){
			if (!('0' <= str[i] && str[i] <= '9'))
				return 0;
			//res = res * 10 + str[i] - '0';
			res = (res << 1) + (res << 3) + (str[i] & 0xf);//位运算提高计算效率	
		}
		return res * flag;
	}
};
