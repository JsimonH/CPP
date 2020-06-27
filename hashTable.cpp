#include<iostream>
#include<vector>
using namespace std;

//标记元素,状态: 存在,删除,空
enum State
{
	EXIST,
	DELETE,
	EMPTY
};

template <class K, class V>
struct Node
{
	pair<K, V> _val;
	State _state;
};

template <class K, class V>
class HashTable
{
public:
	typedef Node<K, V> Node;
	
	HashTable(size_t N = 2)
	{
		//_table.reserve(N);
		//resize之后可以使用[]进行随机访问
		_table.resize(N);
		for (size_t i = 0; i < N; ++i)
		{
			_table[i]._state = EMPTY;
		}
		_size = 0;
	}

	void checkCapacity()
	{
		//超过负载因子,需要增容
		if (_size * 1.0 / _table.size() >= 0.7)
		{
			int newCap = _table.size() * 2;
			//增容不能直接resize,因为元素在新表中的位置可能发生变化
			//_table.resize(newCap);
			
			//建新表,旧表中的每一个元素重新计算它们在新表中的位置
			HashTable<K, V> newHT(newCap);
			for (size_t i = 0; i < _table.size(); ++i)
			{
				//旧表中有效元素全部存入新表
				if (_table[i]._state == EXIST)
				{
					newHT.insert(_table[i]._val);
				}
			}
			_table.swap(newHT._table);
		}
	}

	bool insert(const pair<K, V>& val)
	{
		//检查容量
		checkCapacity();
		int idx = val.first % _table.size();
		while (_table[idx]._state == EXIST)
		{
			if (_table[idx]._val.first == val.first)
				return false;
			++idx;
			//如果走到表尾,则从头开始查找
			if (idx == _table.size())
				idx = 0;
		}
		_table[idx]._val = val;
		_table[idx]._state = EXIST;
		++_size;
		return true;
	}
	
	Node* find(const K& key)
	{
		int idx = key % _table.size();
		//查找时遇到空结束
		while (_table[idx]._state != EMPTY)
		{
			// DELETE,EXIST
			if (_table[idx]._state == EXIST && _table[idx]._val.first == key)
				return &_table[idx];
			++idx;
			//idx是否越界
			if (idx == _table.size())
				++idx;
		}
		return nullptr;
	}

	bool erase(const K& key)
	{
		//查找元素
		Node* node = find(key);
		//如果找到了,伪删除.真删除会对其他元素查找产生影响
		if (node)
		{
			node->_state = DELETE;
			--_size;
			return true;
		}
		return false;
	}

	void htPrint()
	{
		for (size_t i = 0; i < _table.size(); ++i)
		{
			if (_table[i]._state == EXIST)
			{
				cout << _table[i]._val.first << "-->" << _table[i]._val.second << "\t";
			}
		}
		cout << endl;
	}

private:
	vector<Node> _table;
	size_t _size; //存放元素个数
};

void testHT()
{
	HashTable<int, int> ht;
	ht.insert(make_pair(1, 1));
	ht.insert(make_pair(18, 18));
	ht.insert(make_pair(23, 23));
	ht.insert(make_pair(4, 4));
	ht.insert(make_pair(54, 54));
	ht.htPrint();

	ht.erase(18);
	ht.htPrint();
	ht.erase(100);
	ht.htPrint();
}

int main()
{
	testHT();
	return 0;
}
