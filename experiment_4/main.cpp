#include"ADT_declare.h"
#include"link_achieve.h"
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int position(int n)
{
	int deep = 1;
	while (pow(2, deep) - 1 < n) deep++;
	if (deep == 1) return 0;
	else return min(pow(2, deep - 1) - 1, n - pow(2, deep - 2));
}

linkNode<int>* build(int* a, int pos)
{
	if (pos == 0) return NULL;
	int left = position(pos);
	int right = pos - left - 1;
	linkNode<int>* node = new linkNode<int>;
	node->setElement(a[left]);
	node->setLeft(build(&a[0], left));
	node->setRight(build(&a[left + 1], right));
	return node;
}

int main()
{
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	linkTree<int> L;
	L.setRoot(build(a,n));
	queue<int> b;
	L.LevelOrderTraverse(b);
	while (!b.empty())
	{
		cout << b.front() << ' ';
		b.pop();
	}
	delete[]a;
	return 0;
}