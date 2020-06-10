#include<iostream>
#include"linklist_achieve.h"
#include"List-declare.h"
#include<cmath>
using namespace std;

void input(Linklist<int>& list)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		list.push_back(a);
	}
}

int count(Linklist<int>& list)
{
	list.sort();
	Link<int>* p = list.get_head();
	int min = abs(p->getval() - p->getnext()->getval());
	for (p = list.get_head(); p != list.get_tail()->getpre(); p = p->getnext())
	{
		if (abs(p->getval() - p->getnext()->getval()) < min)
			min = abs(p->getval() - p->getnext()->getval());
	}
	return min;
}

int main()
{
	Linklist<int> list;
	input(list);
	int min = count(list);
	cout << min;
}