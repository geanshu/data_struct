#include"ADT_declare.h"
#include"link_achieve.h"
#include<cmath>
#include<iostream>
#include<string>
#include<fstream>
#include<random>
#include<windows.h>
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

void test(int n)
{
	int* a = new int[n];
	string str1 = to_string(n) + ".txt", str2 = "BST_find_" + to_string(n) + ".csv";
	string str3 = "BST_find_error_" + to_string(n) + ".csv";
	ifstream readFile(str1);
	ofstream outfile1(str2, ios::out | ios::trunc);
	ofstream outfile2(str3, ios::out | ios::trunc);
	default_random_engine e;
	e.seed(1);
	for (int i = 0; i < n; i++)
		readFile >> a[i];

	linkTree<int> L;
	L.setRoot(build(a, n));

	outfile1 << "Search Times" << "," << "T/¦Ìs\n";
	int temp = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	while (temp < 100)
	{
		QueryPerformanceCounter(&nBeginTime);
		bool f = L.find(L.get_Root(),a[e() % n]);
		QueryPerformanceCounter(&nEndTime);
		if (f)
		{
			temp++;
			outfile1 << L.Count() << ',' << 1000000 * (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << '\n';
		}
		L.reset_count();
	}
	temp = 0;
	outfile1 << "Search Times" << "," << "T/¦Ìs\n";
	while (temp < 100)
	{
		QueryPerformanceCounter(&nBeginTime);
		bool f = L.find(L.get_Root(), e());
		QueryPerformanceCounter(&nEndTime);
		if (!f)
		{
			temp++;
			outfile2 << L.Count() << ',' << 1000000 * (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart << '\n';
		}
		L.reset_count();
	}
	delete[]a;
	return;
}

int main()
{
	for (int i = 100; i <= 1000000; i *= 10)
	{
		test(i);
		cout << i << "finshed!\n";
	}
	return 0;
}