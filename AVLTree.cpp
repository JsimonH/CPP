#include<iostream>
#include<assert.h>
using namespace std;

template<class T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent; //父亲的指向
	T _val;
	int _bf;  //平衡因子

	AVLNode(const T& val)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _val(val)
		, _bf(0)
	{}
};

template<class T>
class AVLTree
{
public:
	typedef AVLNode<T> Node;
	typedef Node* pNode;

	void RotateR(pNode parent)
	{
		pNode subL = parent->_left;
		pNode subLR = subL->_right;
		//1
		subL->_right = parent;
		//2
		parent->_left = subLR;
		//3
		if (subLR)
			subLR->_parent = parent;
		//4,5
		if (parent != _root)
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
			_root = subL;
			subL->_parent = nullptr;
		}
		//6
		parent->_parent = subL;
		//更新平衡因子
		subL->_bf = parent->_bf = 0;
	}

	void RotateL(pNode parent)
	{
		pNode subR = parent->_right;
		pNode subRL = subR->_left;

		subR->_left = parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		if (parent != _root)
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
			_root = subR;
			subR->_parent = nullptr;
		}
		parent->_parent = subR;
		//更新平衡因子
		parent->_bf = subR->_bf = 0;
	}

	bool insert(const T& val)
	{
		//是否为空树
		if (_root == nullptr)
		{
			_root = new Node(val);
			return true;
		}
		
		pNode cur = _root;
		pNode parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (cur->_val == val)
				return false;
			else if (cur->_val > val)
				cur = cur->_left;
			else
				cur = cur->_right;
		}
		cur = new Node(val);
		if (parent->_val > val)
			parent->_left = cur;
		else
			parent->_right = cur;
		cur->_parent = parent;
		//更新平衡因子,有可能需要调整
		while (parent)
		{
			//如果孩子在左边,左边的高度增加
			if (parent->_left == cur)
				--parent->_bf;
			else
				++parent->_bf;
			//判断平衡因子
			if (parent->_bf == 0)  //更新后平衡因子为0说明之前有一边被补齐了,不会对上面造成影响
				break;
			else if (abs(parent->_bf) == 1)
			{
				//继续向上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if(abs(parent->_bf) == 2)
			{
				//旋转
				if (parent->_bf == 2 && cur->_bf == 1) //右边的右边高,左旋
					RotateL(parent);
				else if (parent->_bf == -2 && cur->_bf == -1) //左边的左边高,右旋
					RotateR(parent);
				//其他情况
				else if (parent->_bf == -2 && cur->_bf == 1) //左边的右边高,左右双旋
				{
					pNode subL = parent->_left;
					pNode subLR = subL->_right;
					int bf = subLR->_bf;
					RotateL(cur);
					RotateR(parent);
					
					//更新parent,subL平衡因子
					if (bf == 1)
					{
						//新插入的节点在subLR的右边(最终放在父节点左边)
						parent->_bf = 0;
						subL->_bf = -1;
					}
					else if (bf == -1)
					{
						//新插入的节点在subLR的左边(最终放在父节点的右边)
						subL->_bf = 0;
						parent->_bf = 1;
					}
				}
				else if (parent->_bf == 2 && cur->_bf == -1) //右边的左边高,右左双旋
				{
					pNode subR = parent->_right;
					pNode subRL = subR->_left;
					int bf = subRL->_bf;
					RotateR(cur);
					RotateL(parent);

					if (bf == 1)
					{
						//新节点在右边
						subR->_bf = 0;
						parent->_bf = -1;
					}
					else if (bf == -1)
					{
						subR->_bf = 1;
						parent->_bf = 0;
					}
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
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

	int height(pNode root)
	{
		if (root == nullptr)
			return 0;
		int left = height(root->_left);
		int right = height(root->_right);

		return left > right ? left + 1 : right + 1;
	}

	bool isAVLTree()
	{
		return _isAVLTree(_root);
	}

	bool _isAVLTree(pNode root)
	{
		if (root == nullptr)
			return true;
		//1.平衡因子绝对值不大于1
		//2.平衡因子和左右子树的高度差要一致
		int left = height(root->_left);
		int right = height(root->_right);
		if (right - left != root->_bf)
		{
			cout << "节点" << root->_val << "平衡因子异常" << endl;
			return false;
		}
		
		return abs(root->_bf) < 2 && _isAVLTree(root->_left)
			&& _isAVLTree(root->_right);
	}

private:
	pNode _root = nullptr;
};

void test()
{
	AVLTree<int>* avl = new AVLTree<int>();
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; ++i)
	{
		avl->insert(arr[i]);
	}
	avl->inOrder();
	cout << avl->isAVLTree() << endl;
}

int main()
{
	test();
	return 0;
}
