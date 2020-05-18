/*
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
*/

class Sum {
public:
    Sum() 
    {
        _sum += _i;
        ++_i;
    }

    static void Init()
    {
        _i = 1;
        _sum = 0;
    }

    static int GetSum() 
    {
        return _sum;
    }

private:
    static int _i;
    static int _sum;
};
int Sum::_i = 1;
int Sum::_sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Sum::Init();
        Sum a[n];
        return Sum::GetSum();
    }
};

// 方法二: 递归+短路求值原理
class Solution {
public:
    int Sum_Solution(int n) {
        int res = n;
        res && (res += Sum_Solution(n - 1));
        return res;
    }
};
