#include"ADT_map.h"
#include"map_matrix.h"
#include<iostream>
#include<algorithm>
using namespace std;

void creat(map_matirx<int>& G, int n, int e)
{
	for (int i = 0; i < n; i++)
	{
		G.setPoint(i, i);
		G.setMark(i, false);
	}
	for (int i = 0; i < e; i++)
	{
		bool f;
		int s1, s2;
		int w;
		cin >> f >> s1 >> s2 >> w;
		if (f)
			w = w * w;
		G.setEdge(s1-1, s2-1, w);
		G.setEdge(s1-1, s2-1, w);
	}
}

int cmin(int* a, bool* b, int n)
{
	int pos = 0, x = 100000;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < x && b[i] == 0)
		{
			x = a[i];
			pos = i;
		}
	}
	return pos;
}

int main()
{

	int n, e;
	cin >> n >> e;
	map_matirx<int> G(n);
	creat(G, n, e);

	int* len = new int[n];
	bool* flag = new bool[n];
	for (int i = 0; i < n; i++)
	{
		len[i] = 100000;
		flag[i] = 0;
	}
	len[0] = 0;
	flag[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int v = cmin(len,flag, n);
		if (len[v] == 100000 || v == n - 1)
			break;
		flag[v] = 1;
		for (int j = G.first(v); j < G.n(); j = G.next(v, j))
		{
			len[j] = min(len[j], len[v] + G.weight(v, j));
		}
	}
	cout << len[n - 1];
	delete[]len;
	delete[]flag;

}