#include<iostream>
using namespace std;

namespace Xner
{
	enum COLOR
	{
		BLACK,
		RED
	};

	//节点存放<Key,Value>数据
	template <class K, class V>
	struct RBNode
	{
		RBNode<K, V>* _left;
		RBNode<K, V>* _right;
		RBNode<K, V>* _parent;
		pair<K, V> _val;
		//颜色
		COLOR _color;

		RBNode(const pair<K, V>& val = pair<K, V>())
			:_left(nullptr)
			, _right(nullptr)
			, _parent(nullptr)
			, _val(val)
			, _color(RED)
		{}
	};

	template<class K, class V>
	class RBTree
	{
	public:
		typedef RBNode<K, V> Node;
		typedef Node* pNode;

		RBTree()
		{
			//构建空的红黑树
			_header = new Node();
			_header->_left = _header;
			_header->_right = _header;
		}

		void RotateR(pNode parent)
		{
			pNode subL = parent->_left;
			pNode subLR = subL->_right;

			subL->_right = parent;
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;
			if (parent != _header->_parent)
			{
				pNode grandpa = parent->_parent;
				if (grandpa->_left == parent)
					grandpa->_left = subL;
				else
					grandpa->_right = subL;
				subL->_parent = grandpa;
			}
			else
			{
				//更新根节点
				_header->_parent = subL;
				subL->_parent = _header;
			}
			parent->_parent = subL;
		}

		void RotateL(pNode parent)
		{
			pNode subR = parent->_right;
			pNode subRL = subR->_left;

			subR->_left = parent;
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;
			if (parent != _header->_parent)
			{
				pNode grandpa = parent->_parent;
				if (grandpa->_left == parent)
					grandpa->_left = subR;
				else
					grandpa->_right = subR;
				subR->_parent = grandpa;
			}
			else
			{
				_header->_parent = subR;
				subR->_parent = _header;
			}
			parent->_parent = subR;
		}

		bool insert(const pair<K, V>& val)
		{
			if (_header->_parent == nullptr)
			{
				//空树,创建根节点
				pNode root = new Node(val);
				root->_color = BLACK;
				root->_parent = _header;
				_header->_parent = root;

				_header->_left = root;
				_header->_right = root;
				return true;
			}
			//从根开始搜索
			pNode cur = _header->_parent;
			pNode parent = nullptr;
			while (cur)
			{
				parent = cur;
				//按照Key值确定位置,Key不能重复
				if (cur->_val.first == val.first)
					return false;
				else if (cur->_val.first > val.first)
					cur = cur->_left;
				else
					cur = cur->_right;
			}
			cur = new Node(val);
			if (parent->_val.first > cur->_val.first)
				parent->_left = cur;
			else
				parent->_right = cur;
			cur->_parent = parent;

			//调整和更新(颜色):连续的红色需要调整
			while (cur != _header->_parent && cur->_parent->_color == RED)
			{
				parent = cur->_parent;
				pNode grandpa = parent->_parent;
				if (grandpa->_left == parent)
				{
					pNode uncle = grandpa->_right;
					//uncle存在且为红
					if (uncle && uncle->_color == RED)
					{
						//修改颜色
						parent->_color = uncle->_color = BLACK;
						grandpa->_color = RED;
						//继续向上更新
						cur = grandpa;
					}
					//uncle存在且为黑
					else
					{
						//如果存在双旋的情况,可以先进行一次单旋,使它变成单旋的情况
						if (parent->_right == cur)
						{
							RotateL(parent);
							swap(cur, parent);
						}
						//以grandpa为轴右旋,修改颜色
						RotateR(grandpa);
						parent->_color = BLACK;
						grandpa->_color = RED;
						//停止调整
						break;
					}
				}
				else
				{
					pNode uncle = grandpa->_left;
					if (uncle && uncle->_color == RED)
					{
						//修改颜色
						uncle->_color = parent->_color = BLACK;
						grandpa->_color = RED;
						//继续向上更新
						cur = grandpa;
					}
					else
					{
						//判断是否有双旋的场景
						if (parent->_left == cur)
						{
							RotateR(parent);
							swap(cur, parent);
						}
						RotateL(grandpa);
						parent->_color = BLACK;
						grandpa->_color = RED;
						break;
					}
				}
			}
			//根的颜色始终是黑色
			_header->_parent->_color = BLACK;
			//更新_header->_left和_header->_right,分别指向树的最左节点和最右节点
			_header->_left = leftMost();
			_header->_right = rightMost();
			return true;
		}

		pNode leftMost()
		{
			pNode cur = _header->_parent;
			while (cur && cur->_left != nullptr)
			{
				cur = cur->_left;
			}
			return cur;
		}

		pNode rightMost()
		{
			pNode cur = _header->_parent;
			while (cur && cur->_right != nullptr)
			{
				cur = cur->_right;
			}
			return cur;
		}

		void _inOrder(pNode root)
		{
			if (root)
			{
				_inOrder(root->_left);
				cout << root->_val.first << "<=>" << root->_val.second << " ";
				_inOrder(root->_right);
			}
		}

		void inOrder()
		{
			_inOrder(_header->_parent);
			cout << endl;
		}

		bool isRBTree()
		{
			pNode root = _header->_parent;
			if (root == nullptr)
				return true;
			if (root->_color == RED)
			{
				cout << "根的颜色必须是黑色" << endl;
				return false;
			}
			//每条路径黑色节点个数相同
			//可以任意遍历一条路径,例如最右路径
			pNode cur = root;
			int blackCount = 0;
			while (cur)
			{
				if (cur->_color == BLACK)
					++blackCount;
				cur = cur->_right;
			}
			int k = 0;
			return _isRBTree(root, k, blackCount);
		}

		bool _isRBTree(pNode root, int curBlackCount, int totalBlackCount)
		{
			//每条路径上黑色节点个数相同
			if (root == nullptr)
			{
				if (curBlackCount != totalBlackCount)
				{
					cout << "每条路径黑色节点个数不同" << endl;
					return false;
				}
				return true;
			}
			if (root->_color == BLACK)
				++curBlackCount;

			//没有红色节点连续
			pNode parent = root->_parent;
			if (parent->_color == RED && root->_color == RED)
			{
				cout << "有连续红色的节点" << endl;
				return false;
			}

			return _isRBTree(root->_left, curBlackCount, totalBlackCount)
				&& _isRBTree(root->_right, curBlackCount, totalBlackCount);
		}

	private:
		pNode _header;
	};

	void testRBTree()
	{
		RBTree<int, int> rbt;
		rbt.insert(make_pair(1, 1));
		rbt.insert(make_pair(10, 1));
		rbt.insert(make_pair(-1, 1));
		rbt.insert(make_pair(-2, 1));
		rbt.insert(make_pair(100, 1));
		rbt.insert(make_pair(19, 1));
		rbt.insert(make_pair(21, 1));
		rbt.inOrder();
		cout << rbt.isRBTree() << endl;
	}
}

int main()
{
	Xner::testRBTree();
	return 0;
}
