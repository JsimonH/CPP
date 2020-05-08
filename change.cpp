/* 神奇的数字
在这个特殊的假期里，由于牛牛在家特别无聊，于是他发明了一个小游戏，游戏规则为：将字符串数字中为偶数位的数字进行翻转，将翻转后的结果进行输出。
input: "1234"
output: "1432"
*/

class Solution {
public:
    string change(string number) {
        int left = 0;
        int right = number.size() - 1;
        while(left < right)
        {
            while((number[left] - '0') % 2 != 0)
                ++left;
            while((number[right] - '0') % 2 != 0)
                --right;
            if(left < right)
            {
                swap(number[left], number[right]);
                ++left;
                --right;
            }
        }
        return number;
    }
};
