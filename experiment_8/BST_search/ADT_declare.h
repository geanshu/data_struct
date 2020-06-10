#pragma once
#include<queue>
template<typename T>
class BinNode
{
public:
	virtual void setElement(T e)=0;
	virtual void setLeft(BinNode* rt) = 0;
	virtual void setRight(BinNode* rt) = 0;
	virtual bool isLeaf() = 0;
	virtual BinNode* right() = 0;
	virtual BinNode* left() = 0;
	virtual T get_val() = 0;
};


template<typename T>
class BinTree
{
public:
	virtual bool BitreeEmpty(BinNode<T>* rt)=0;
	virtual void Preorder(BinNode<T>* rt, std::queue<T>& a)=0;
	virtual void Inorder(BinNode<T>* rt, std::queue<T>& a)=0;
	virtual void Postorder(BinNode<T>* rt, std::queue<T>& a)=0;
	virtual void LevelOrderTraverse(std::queue<T>& a)=0;
};
