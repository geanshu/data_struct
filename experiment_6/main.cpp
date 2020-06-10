#include"ADT_map.h"
#include"map_matrix.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

void creat(map_matirx<int>& G1,map_matirx<int>& G2, int n, int e)
{
	for (int i = 0; i < n; i++)
	{
		G1.setPoint(i, i + 1);
		G1.setMark(i, false);
		G2.setPoint(i, i + 1);
		G2.setMark(i, false);
	}
	for (int i = 0; i < e; i++)
	{
		int s1, s2;
		cin >> s1 >> s2;
		G1.setEdge(s1-1, s2-1, 1);
		G2.setEdge(s2-1, s1-1, 1);
	}
}

int main()
{

	int n, e;
	cin >> n >> e;
	map_matirx<int> G1(n),G2(n);
	creat(G1, G2, n, e);
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		vector<int> l1, l2;
		l1 = G1.BFS(i);
		l2 = G2.BFS(i);
		for (vector<int>::iterator it = l2.begin(); it != l2.end(); it++)
		{
			l1.push_back(*it);
		}
		sort(l1.begin(), l1.end());
		l1.erase(unique(l1.begin(), l1.end()), l1.end());
		if (l1.size() == n)
			num++;
		G1.reset_mark();
		G2.reset_mark();
	}
	cout << num;
}