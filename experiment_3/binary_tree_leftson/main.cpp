#include"ADT_declare.h"
#include"leftson_achieve.h"
#include<iostream>
#include<queue>

using namespace std;
int x=0;
/*void change(int* post, int* in,int len,int x,Tree<int>& L)
{
	if (len == 0)
		return;
	else
	{
		int temp = post[len - 1];
		int index = 0;
		while (in[index] != temp)
			index++;
		L.insert(temp, x);
		int len1 = index, len2 = len - index - 1;
		int* post1 = new int[len1];
		int* post2 = new int[len2];
		int* in1 = new int[len1];
		int* in2 = new int[len2];
		for (int i = 0; i < len; i++)
		{
			if (i < index)
				in1[i] = in[i];
			else if (i > index)
				in2[i - index - 1] = in[i];
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
		change(post1, in1, len1,L.get_size()-1,L);
		change(post2, in2, len2,L.get_size()-1,L);
		delete[]post1;
		delete[]post2;
		delete[]in1;
		delete[]in2;
	}
}*/

void creat(Tree<int>& L)
{
	int cnt = 0;
	int p, c;//父结点数据,子结点数据
	queue< BinNode<int>* > que;
	que.push(L.get_root());
	while (cin >> p >> c)
	{
		if (p == '#' && c == '#') break;
		L.CreatBitree(p, c,que);
	}

}

int main()
{
	cout << "请输入二叉树节点数\n";
	int n;
	cin>> n;
	Tree<int> L(n);
	cout << "请输入根节点数据：\n";
	int a;
	cin >> a;
	L.set_root(a);
	cout << "请以层序依次输入各子结点数据（以# #作为结束标志）：";
	cout << "\n（数据类型为单个字符，如输入A B表示父结点数据是A，有一个子结点数据是B）\n";
	creat(L);
	cout<<"\n这棵二叉树层次遍历的结果为：\n";
	queue<int> x;
	L.LevelOrderTraverse(0,x);
	while (!x.empty())
	{
		cout << x.front() << " ";
		x.pop();
	}
	return 0;
 }