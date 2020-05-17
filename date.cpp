#include<iostream>
using namespace std;

class Date
{
public:
	// 获取某月的天数
	int GetMonthDay(int year, int month)
	{
		int monthDays[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		// 如果是闰年的2月份,有29天
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		{
			monthDays[2] = 29;
		}
		return monthDays[month];
	}

	// 构造函数
	Date(int year = 2000, int month = 1, int day = 1)
	{
		if (year > 0 && month > 0 && month <= 12
			&& day > 0 && day <= GetMonthDay(year, month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "日期不合理" << endl;
		}
	}

	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	// 赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}

	// 析构函数
	~Date()
	{}

	// 日期+=天数
	Date& operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13)
			{
				++_year;
				_month = 1;
			}
		}
		return *this;
	}

	// 日期+天数
	Date operator+(int day)
	{
		Date ret(*this);  // 拷贝构造一个ret
		ret += day;  // 复用上面的
		return ret;
	}

	// 日期-天数
	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}

	// 日期-=天数
	Date& operator-=(int day)
	{
		if (day < 0)
		{
			return *this += -day;
		}

		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
		return *this;
	}

	// 前置++
	Date& operator++()
	{
		*this += 1;
		return *this;  // 返回++之后的值
	}

	// 后置++
	Date operator++(int) // (int)是为了构成函数重载
	{
		Date tmp(*this);
		*this += 1;
		return tmp;  // 返回++之前的值
	}

	// 后置--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	// 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	// >运算符重载
	inline bool operator>(const Date& d)
	{
		if (_year > d._year   // 比较年
			|| _year == d._year && _month > d._month  // 年相等,比较月份
			|| _year == d._year && _month == d._month && _day > d._day)  // 年月相等,比较天
		{
			return true;
		}
		return false;
	}

	// ==运算符重载
	inline bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	// >=运算符重载
	bool operator >= (const Date& d)
	{
		return (*this > d || *this == d);
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this > d);
	}

	// !=运算符重载
	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// 日期-日期 返回天数
	int operator-(const Date& d)
	{
		Date max = *this;  
		Date min = d;
		int flag = 1;  // 默认前一个日期比后一个日期大

		if (*this < d)  // 如果实际是后一个日期大于前一个,则交换它们,flag改变符号
		{
			max = d;
			min = *this;
			flag = -1;
		}

		int days = 0;  // 两个日期相差的天数
		while (min != max)
		{
			++min;
			++days;
		}
		return days * flag;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	cout << "无参构造:" << endl;
	Date d1;  // 无参构造,调用全缺省构造函数
	d1.Print();

	cout << "传参构造:" << endl;
	Date d2(2020, 5, 17);  
	d2.Print();
	
	cout << "拷贝构造:" << endl;
	Date d3(d2);
	d3.Print();

	cout << "日期赋值:" << endl;
	d3 = d1;
	d3.Print();

	cout << "日期+天数(原本的日期不会改变):" << endl;
	Date d4 = d2 + 10;
	Date d5 = d2 + 100;
	Date d6 = d2 + 1000;
	d4.Print();
	d5.Print();
	d6.Print();

	cout << "日期+=天数(原本的日期会改变):" << endl;
	Date d7 = d2 += 10;
	Date d8 = d2 += 100;
	Date d9 = d2 += 1000;
	d7.Print();
	d8.Print();
	d9.Print();

	cout << "日期-=天数(原本的日期会改变):" << endl;
	Date d10 = d2 -= 10;
	Date d11 = d2 -= 100;
	Date d12 = d2 -= 1000;
	d10.Print();
	d11.Print();
	d12.Print();

	cout << "日期-天数(原本的日期不会改变):" << endl;
	Date d13 = d2 - 10;
	Date d14 = d2 - 100;
	Date d15 = d2 - 1000;
	d13.Print();
	d14.Print();
	d15.Print();

	cout << "日期-日期:" << endl;
	int ret1 = d2 - d1;
	int ret2 = d1 - d2;
	cout << ret1 << endl;
	cout << ret2 << endl;
	return 0;
}
