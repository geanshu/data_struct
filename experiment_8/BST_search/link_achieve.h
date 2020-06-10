#pragma once
#include"ADT_declare.h"
#include<queue>
using namespace std;
template<typename T>
class linkNode :public BinNode<T>
{
private:
	T val;
	linkNode* lc;
	linkNode* rc;
public:
	linkNode();
	T get_val() {return val;}
	void setElement(T e) { val = e; }
	linkNode* right(){return rc;}
	linkNode* left() {return lc;}
	void setRight(BinNode<T>* b) { rc = (linkNode*)b; }
	void setLeft(BinNode<T>* b){lc = (linkNode*)b; }
	bool isLeaf() { return lc == 0 && rc == 0; }
};

template<typename T>
class linkTree :public BinTree<T>
{
private:
	linkNode<T>* Root;
	int size;
	int count;
public:
	linkTree();
	~linkTree();
	//linkNode<T>* Create(T* a, int pos, int len);
	void setRoot(linkNode<T>* rt) { Root = rt; }
	bool BitreeEmpty(BinNode<T>* rt) { return true; }
	void clear();
	void Preorder(BinNode<T>* rt, queue<T>& a);
	void Inorder(BinNode<T>* rt, queue<T>& a);
	void Postorder(BinNode<T>* rt, queue<T>& a);
	void LevelOrderTraverse(queue<T>& a);
	linkNode<T>* get_Root() { return Root; }
	int Count() { return count; }
	void reset_count() { count = 0; }
	int find(BinNode<T>* root, const T& val);
};

template<typename T>
inline linkNode<T>::linkNode()
{
	lc = 0;
	rc = 0;
	val = 0;
}

template<typename T>
inline linkTree<T>::linkTree()
{
	count = 0;
	size = 0;
}

template<typename T>
inline linkTree<T>::~linkTree()
{
	clear();
}

/*template<typename T>
linkNode<T>* linkTree<T>::Create(T* a,int pos,int len)
{
	if(len<=0)
		return 0;
	else
	{
		linkNode<T>* root = new linkNode<T>;
		int pos1, pos2, len1 = pos, len2 = len - pos - 1;
		for (int i = 0; i < len; i++)
		{
			if (i < pos)
				a1[i] = a[i];
			else if (i > pos)
				a2[i-pos-1] = a[i];
		}

		int deep1 = log(len1) / log(2);
		if (pow(2, deep1) != len1)
			deep1++;
		int len = len1 - (pow(2, deep1 - 1) - 1);
		if (len <= pow(2, deep1 - 2))
			pos1 = pow(2, deep1 - 2) - 1 + len;
		else
			pos1 = pow(2, deep1 - 2) - 1 + pow(2, deep1 - 2);

		int deep2 = log(len2) / log(2);
		if (pow(2, deep2) != len1)
			deep2++;
		int len = len2 - (pow(2, deep2 - 1) - 1);
		if (len <= pow(2, deep2 - 2))
			pos2 = pow(2, deep2 - 2) - 1 + len;
		else
			pos2 = pow(2, deep2 - 2) - 1 + pow(2, deep2 - 2);
		root->setLeft(Create(&a[0], pos1,len1,));
		root->setElement(a[pos])]);
		root->setRight(Create(&a[pos+1], pos2,len2));
		return root;
	}
}
*/
template<typename T>
inline void linkTree<T>::clear()
{
	delete Root;
}

template<typename T>
void linkTree<T>::Preorder(BinNode<T>* rt,queue<T>& a)
{
	if (rt == 0) return;
	a.push( rt->get_val());
	Preorder(rt->left(),a);
	Preorder(rt->right(),a);
}

template<typename T>
void linkTree<T>::Inorder(BinNode<T>* rt, queue<T>& a)
{
	if (rt == 0) return;
	Inorder(rt->left(),a);
	a.push(rt->get_val());
	Inorder(rt->right(),a);
}

template<typename T>
void linkTree<T>::Postorder(BinNode<T>* rt, queue<T>& a)
{
	if (rt == 0) return;
	Postorder(rt->left(),a);
	Postorder(rt->right(),a);
	a.push(rt->get_val());
}

template<typename T>
inline void linkTree<T>::LevelOrderTraverse(queue<T>& a)
{
	queue<BinNode<T>*> q;
	if (Root == 0)
		return;
	q.push(Root);
	while (!q.empty())
	{
		//出队保存队头并访问
		BinNode<T>* front = q.front();
		a.push(front->get_val());
		q.pop();
		//将出队结点的左子树根入队
		if (front->left())
			q.push(front->left());
		//将出队结点的右子树根入队
		if (front->right())
			q.push( front->right());
	}
}

template<typename T>
inline int linkTree<T>::find(BinNode<T>* root, const T& val)
{
	if (root == NULL)return false;
	count++;
	if (val < root->get_val())
		return find(root->left(), val);
	else if (val > root->get_val())
		return find(root->right(), val);
	else
		return true;
}