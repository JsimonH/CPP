/* 把字符串转换成整数
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0

输入: +2147483647
      1a33
输出: 2147483647
      0
*/

class Solution {
public:
    int StrToInt(string str) {
        if(str.empty())
        {
            return 0;
        }
        int flag;  //标志正负
        if(str[0] == '+')
        {
            symbol = 1;
            str[0] = '0';
        }
        if(str[0] == '-')
        {
            symbol = -1;
            str[0] = '0';
        }
        int num = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] < '0'  || str[i] > '9')
            {
                return 0;
            }
            else
            {
                num *= 10;
                num += str[i]-'0';
            }
        }
        num *= flag;
       if(num > INT_MAX || num < INT_MIN)  // 判断溢出
            return 0;
        return num;
    }
};

