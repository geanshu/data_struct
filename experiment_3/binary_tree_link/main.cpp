#include"ADT_declare.h"
#include"link_achieve.h"
#include<iostream>
#include<queue>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int* post = new int[n];
	int* in = new int[n];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	linkTree<int> L;
	L.setRoot(L.Create(post, in, n ));
	queue<int> a;
	L.LevelOrderTraverse(a);
	while (!a.empty())
	{
		cout << a.front() << ' ';
		a.pop();
	}
	delete[]post;
	delete[]in;
	return 0;
}