#include"ADT_map.h"
#include"map_matrix.h"
#include<iostream>

using namespace std;

void creat(map_matirx<char>& G, int n, int e)
{
	for (int i = 0; i < n; i++)
	{
		char val;
		cin >> val;
		G.setPoint(i, val);
		G.setMark(i, false);
	}
	for (int i = 0; i < e; i++)
	{
		char s1, s2;
		int w;
		cin >> s1 >> s2 >> w;
		int p1 = G.findPoint(s1), p2 = G.findPoint(s2);
		G.setEdge(p1, p2, w);
	}
}

int main()
{

	int n, e;
	cin >> n >> e;
	map_matirx<char> G(n);
	creat(G, n, e);

	int** edge = new int* [n];
	for (int i = 0; i < n; i++)
		edge[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			edge[i][j] = G.weight(i, j);
		}
	}

	int* num = new int[n];
	for (int i = 0; i < n; i++)
	{
		num[i] = 0;
		for (int j = 0; j < n; j++)
		{
			if (edge[i][j] != 0)
				num[i]++;
		}
	}
	int maxPoint = 0, maxsum = num[0];
	for (int i = 1; i < n; i++)
	{
		if (num[i] > maxsum||(num[i]==maxsum&&G.getPoint(i)>G.getPoint(maxPoint)))
		{
			maxPoint = i;
			maxsum = num[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << edge[i][j] << ' ';
		}
		cout << endl;
	}
	cout << G.getPoint(maxPoint) <<' '<< num[maxPoint];

	for (int i = 0; i < n; i++)
		delete[]edge[i];
	delete[]edge;
	delete[]num;
}