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
public:
	linkTree();
	~linkTree();
	linkNode<T>* Create(T* post,T* in,int len);
	void setRoot(linkNode<T>* rt) { Root = rt; }
	bool BitreeEmpty(BinNode<T>* rt) { return true; }
	void clear();
	void Preorder(BinNode<T>* rt, queue<T>& a);
	void Inorder(BinNode<T>* rt, queue<T>& a);
	void Postorder(BinNode<T>* rt, queue<T>& a);
	void LevelOrderTraverse(queue<T>& a);
	linkNode<T>* get_Root() { return Root; }
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
	size = 0;
}

template<typename T>
inline linkTree<T>::~linkTree()
{
	clear();
}

template<typename T>
inline linkNode<T>* linkTree<T>::Create(T* post,T* in,int len)
{
	if(len<=0)
		return 0;
	else
	{
		linkNode<T>* root = new linkNode<T>;
		root->setElement(post[len - 1]);
		int index = 0;
		while (in[index] != post[len - 1])
			index++;

		int len1 = index,len2=len-index-1;
		T* post1 = new T[index];
		T* post2 = new T[len-index-1];
		T* in1 = new T[index];
		T* in2 = new T[len-index-1];
		for (int i = 0; i < len; i++)
		{
			if (i < index)
			{
				in1[i] = in[i];
			}
			else if (i > index)
			{
				in2[i - index - 1] = in[i];
			}
		}
		for (int i = 0; i < len - 1; i++)
		{
			if (i < index)
				post1[i] = post[i];
			else
				post2[i - index] = post[i];
		}

		if (len == 1)
			len1 = len2 = 0;
		root->setLeft(Create(post1, in1,len1));
		root->setRight(Create(post2, in2,len2));
		delete[]post1;
		delete[]post2;
		delete[]in1;
		delete[]in2;
		return root;
	}
}

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

