#pragma once
#include<queue>
template<typename T>
class BinNode
{
public:
	virtual void setElement(T elem)=0;
	virtual void setLeft(int n) = 0;
	virtual void setRight(int n) = 0;
	virtual bool isLeaf() = 0;
	virtual int right() = 0;
	virtual int left() = 0;
	virtual T get_val() = 0;
};


template<typename T>
class BinTree
{
public:
	BinNode<T>* root;
	BinNode<T>* CreatBitree(T p, T c, std::queue<T>& que);
	bool BitreeEmpty();
	void preorder(BinNode<T>* rt, std::queue<T>& a);
	void Inorder(BinNode<T>* rt, std::queue<T>& a);
	void postorder(BinNode<T>* rt, std::queue<T>& a);
	void LevelOrderTraverse(BinNode<T>* rt, std::queue<T>& a);
};
