namespace Xner
{
	class string
	{
	public:
		// string s2("hello");
		string(const char* str = "")
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_size = strlen(str);
			_capacity = _size;
		}

		// string s3(s2);
		string(const string& s)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
			_size = s._size;
			_capacity = s._capacity;
		}

		// s1 = s3
		string& operator=(const string &s)
		{
			if (this != &s)
			{
				char* tmp = new char[strlen(s._str) + 1];
				strcpy(tmp, s._str);
				_size = s._size;
				_capacity = s._capacity;
				delete[] _str;
				_str = tmp;
			}
			return *this;
		}

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		// 尾插字符
		void PushBack(char c)
		{
			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}
			_str[_size] = c;
			++_size;
			_str[_size] = '\0';  // 细节在此
		}

		string& operator+=(char c)
		{
			PushBack(c);
			return *this;
		}

		// 尾插字符串
		void Append(const char* str)
		{
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(const char* str)
		{
			Append(str);
			return *this;
		}

		// 清空字符串
		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

		void swap(string& s);

		const char* c_str() const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		size_t capacity() const
		{
			return _capacity;
		}

		// 字符串判空
		bool empty() const
		{
			if (_size == 0)
				return true;
			return false;
		}

		void reserve(size_t newCapacity)
		{
			if (newCapacity > _capacity)
			{
				char* new_str = new char[newCapacity + 1];
				strcpy(new_str, _str);
				delete[] _str;
				_str = new_str;
				_capacity = newCapacity;
			}
		}

		void resize(size_t newSize, char c = '\0')
		{
			if (newSize < _size)
			{
				_str[newSize] = '\0';
				_size = newSize;
			}
			else
			{
				if (newSize > _capacity)
				{
					reserve(newSize);
				}

				for (size_t i = _size; i < newSize; ++i)
				{
					_str[i] = c;
				}
				_str[newSize] = '\0';
				_size = newSize;
			}
		}

		char& operator[](size_t index)
		{
			assert(index < _size);
			return _str[index];
		}

		const char& operator[](size_t index) const
		{
			assert(index < _size);
			return _str[index];
		}

		bool operator<(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret < 0;
		}

		bool operator<=(const string& s)
		{
			return *this < s || *this == s;
		}

		bool operator>(const string& s)
		{
			return !(*this <= s);
		}

		bool operator>=(const string& s)
		{
			return !(*this < s);
		}

		bool operator==(const string& s)
		{
			int ret = strcmp(_str, s._str);
			return ret == 0;
		}

		bool operator!=(const string& s)
		{
			return !(*this == s);
		}

		// 返回c在string中第一次出现的位置
		size_t find(char c, size_t pos = 0) const
		{
			for (size_t i = pos; i < _size; ++i)
			{
				if (_str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}

		// 返回子串s在string中第一次出现的位置
		size_t find(const char* s, size_t pos = 0) const
		{
			char* p = strstr(_str, s);
			if (p == nullptr)
			{
				return npos;
			}
			else
			{
				return p - _str;
			}
		}

		// 在pos位置上插入字符c，并返回该字符的位置
		string& insert(size_t pos, char c)
		{
			assert(pos <= _size);

			if (_size == _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
				reserve(newcapacity);
			}

			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + 1] = _str[end];
				--end;
			}
			_str[pos] = c;
			++_size;

			return *this;
		}

		//在pos位置上插入字符串str，并返回该字符的位置
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);

			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}

			// 挪动数据
			int end = _size;
			while (end >= (int)pos)
			{
				_str[end + len] = _str[end];
				--end;
			}
			strncpy(_str + pos, str, len);
			_size += len;

			return *this;
		}

		// 删除pos位置上的元素，并返回该元素的下一个位置
		string& erase(size_t pos, size_t len)
		{
			assert(pos < _size);

			if (len >= _size - pos)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				size_t i = pos + len;
				while (i <= _size)
				{
					_str[i - len] = _str[i];
					++i;
				}

				_size -= len;
			}
			return *this;
		}

	private:
		char* _str;
		size_t _capacity;
		size_t _size;

		static size_t npos;
	};

	size_t string::npos = -1;  // 静态成员变量要在类外初始化

	void Test_string()
	{
		string s1;
		cout << s1.size() << endl;
		cout << s1.capacity() << endl;

		string s2("hello");
		for (size_t i = 0; i < s2.size(); ++i)
		{
			cout << s2[i];
		}
		cout << endl;

		// 拷贝构造
		string s3(s2);
		string::iterator s = s3.begin();
		while (s != s3.end())
		{
			cout << *s;
			++s;
		}
		cout << endl;

		// operator赋值
		s1 = s3;
		cout << s1.c_str() << endl;

		s1.PushBack(' ');   // 尾插字符
		s1 += "world";   // +=字符串
		s1 += '!';   // +=字符
		s1.Append("123");   // 尾插字符串
		cout << s1.c_str() << endl;
		s1.clear();   // 清空字符串
		cout << s1.c_str() << endl;

		// 在pos位置插入字符
		s1 += "abc";
		s1.insert(1, '1');
		s1.insert(0, 'x');
		cout << s1.c_str() << endl;
		// 在pos位置插入字符串
		s1.insert(2, "abc");
		cout << s1.c_str() << endl;
		s1.erase(2, 1);
		cout << s1.c_str() << endl;
	}
}
