#include<iostream>
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode<T>* _left;
	BSTNode<T>* _right;
	T _val;

	BSTNode(const T& val)
		:_left(nullptr)
		, _right(nullptr)
		, _val(val)
	{}
};

template<class T>
class BSTree
{
public:
	typedef BSTNode<T> Node;
	typedef Node* pNode;

	bool insert(const T& val)
	{
		//空树
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		
		//找合适插入的位置
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;  //更新父节点
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		
		cur = new Node(val);
		//判断节点的位置
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		
		return true;
	}

	bool erase(const T& val)
	{
		//空树不能删除
		if (_root == nullptr)
			return false;
		
		//搜索
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			if (cur->_val == val)
				break;
			else if (cur->_val > val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}	
		}
		//判断节点是否存在
		if (cur == nullptr)
			return false;
		
		//要删除节点的左子树为空
		if (cur->_left == nullptr)
		{
			//根和其他节点
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else
				_root = cur->_right;  //更新根节点
			delete cur;
			cur = nullptr;
		}

		//要删除节点的右子树为空
		else if (cur->_right == nullptr)
		{
			if (cur != _root)
			{
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			else
				_root = cur->_left;  //更新根节点
			delete cur;
			cur = nullptr;
		}

		//要删除节点的左右子树都不为空
		else
		{
			//1.找左子树的最右节点或右子树的最左节点
			pNode next = cur->_left;
			pNode parent = cur;
			while (next->_right)
			{
				parent = next;
				next = next->_right;
			}
			//交换值
			cur->_val = next->_val;
			if (parent->_left == next)
				parent->_left = next->_left;
			else
				parent->_right = next->_left;
			//删除找的节点
			delete next;
			next = nullptr;
		}
		return true;
	}

	pNode find(const T& val)
	{
		pNode cur = _root;
		while (cur)
		{
			if (cur->_val == val)
				return cur;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		return cur;
	}

	void _inOrder(pNode root)
	{
		if (root)
		{
			_inOrder(root->_left);
			cout << root->_val << " ";
			_inOrder(root->_right);
		}
	}

	void inOrder()
	{
		_inOrder(_root);
		cout << endl;
	}

private:
	pNode _root = nullptr;
};
