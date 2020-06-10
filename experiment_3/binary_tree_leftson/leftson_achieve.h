#pragma once
#include<queue>
#include"ADT_declare.h"
using namespace std;

template<typename T>
class Node :public BinNode<T>
{
public:
	Node();
	Node(T elem, int l, int r, bool e) :val(elem), right_brother(r), left_son(l) {};
	void setElement(T elem);
	void setLeft(int n);
	void setRight(int n);
	void setPar(int n);
	bool isLeaf();
	int get_par();
	int right();
	int left();
	T get_val();
private:
	T val;
	int right_brother;
	int parents;
	int left_son;
};

template<typename T>
class Tree :public BinTree<T>
{
public:
	Tree(int n);
	~Tree();
	Node<T>* get_root();
	void set_root(T n);
	bool BitreeEmpty();
	void preorder(int n, queue<T>& a);
	void Inorder(int n, queue<T>& a);
	void postorder(int n, queue<T>& a);
	void LevelOrderTraverse(int n, queue< T >& a);
	void insert(T x, int pos);
	int get_lc(int pos);
	int get_rc(int pos);
	int get_size();
	void CreatBitree(T p,T c, queue<BinNode<int>*>& que);
	int count(int u);
private: 
	Node<T>* root;
	Node<T>* tree;
	int maxsize;
	int size;
	int cnt;
};

template<typename T>
inline Node<T>::Node()
{
	right_brother = -1;
	left_son = -1;
	parents = -1;
	val = 0;
}

template<typename T>
inline void Node<T>::setElement(T elem)
{
	val = elem;
	return;
}

template<typename T>
inline void Node<T>::setLeft(int n)
{
	left_son = n;
	return;
}

template<typename T>
inline void Node<T>::setRight(int n)
{
	right_brother = n;
	return;
}

template<typename T>
inline void Node<T>::setPar(int n)
{
	parents = n;
}

template<typename T>
inline bool Node<T>::isLeaf()
{
	if (right_brother == 0 && left_son == 0)
		return true;
	else
		return false;
}

template<typename T>
inline int Node<T>::get_par()
{
	return parents;
}

template<typename T>
inline int Node<T>::left()
{
	return left_son;
}

template<typename T>
inline int Node<T>::right()
{
	return right_brother;
}

template<typename T>
inline T Node<T>::get_val()
{
	return val;
}

template<typename T>
inline Tree<T>::Tree(int n)
{
	tree = new Node<T>[n];
	root = &tree[0];
	maxsize = n;
	size = 0;
	cnt = 0;
}

template<typename T>
inline Tree<T>::~Tree()
{
	delete []tree;
}

template<typename T>
inline Node<T>* Tree<T>::get_root()
{
	return root;
}

template<typename T>
inline void Tree<T>::set_root(T n)
{
	tree[0].setElement(n);
	size++;
}

template<typename T>
inline bool Tree<T>::BitreeEmpty()
{
	return size;
}

template<typename T>
void Tree<T>::preorder(int n,queue<T>& a)
{
	if (n == -1) return;
	a.push(tree[n].get_val());
	preorder(tree[n].left());
	preorder(tree[n].right());
}

template<typename T>
void Tree<T>::Inorder(int n, queue<T>& a)
{
	if (n == -1) return;
	Inorder(tree[n].left(), queue<T> & a);
	Inorder(tree[n].right(), queue<T> & a);
	a.push(tree[n].get_val());
}

template<typename T>
void Tree<T>::postorder(int n, queue<T>& a)
{
	if (n == -1) return;
	postorder(tree[n].left(), queue<T> & a);
	a.push(tree[n].get_val());
	postorder(tree[n].right(), queue<T> & a);
}

template<typename T>
inline void Tree<T>::LevelOrderTraverse(int u, queue<T>& a)
{
	int n = count(0);
	for (int i = 0; i < n; i++)
		a.push(tree[i].get_val());
}

/*
template<typename T>
inline void Tree<T>::insert(T x, int pos)
{
	if (size == 0)
	{
		tree[0].setElement(x);
		tree[0].setEmpty(true);
		size++;
	}
	else if (tree[pos].left() == -1)
	{
		tree[pos].setLeft(size);
		tree[size] = Node<T>(x, -1, -1, true);
		tree[size].setPar(pos);
		size++;
	}
	else if(tree[tree[pos].left()].right() == -1)
	{
		tree[tree[pos].left()].setRight(size);
		tree[size] = Node<T>(x, -1, -1, true);
		tree[size].setPar(pos);
		size++;
	}
	else
	{
		insert(x, tree[pos].get_par());
	}
}
*/

template<typename T>
inline int Tree<T>::get_lc(int pos)
{
	if (tree[tree[pos].left()].get_e())
		return tree[pos].right();
	else
		return tree[tree[pos].left()].right();
}

template<typename T>
inline int Tree<T>::get_rc(int pos)
{
	if (!tree[tree[pos].left()].get_e())
		return tree[pos].right();
	else
		return tree[tree[pos].left()].right();
}

template<typename T>
inline int Tree<T>::get_size()
{
	return size;
}

template<typename T>
void Tree<T>::CreatBitree(T p,T c,queue< BinNode<int>* > &que)
{


		cnt++;
		if (cnt + 1 > maxsize)
		{
			return;
		}
		while (que.front()->get_val()!=p && !que.empty())
		{
			que.pop();
		}

		if (que.empty())
		{
			return;//不能连成树
		}

		if (que.front()->left() == -1)//最左
		{
			tree[cnt];
			(tree[cnt]).setElement(c);
			que.front()->setLeft(cnt);
			que.push(&tree[cnt]);
			size++;
		}
		else//右邻
		{
			tree[cnt].setElement(c);
			int x = que.front()->left();
			while (tree[x].right() != -1)
				x = tree[x].right();
			tree[x].setRight(cnt);
			que.push(&tree[cnt]);
			size++;
		}
}

template<typename T>
int Tree<T>::count(int u)

{
	if (u == -1) return 0;
	return 1 + count(tree[u].left()) + count(tree[u].right());
}