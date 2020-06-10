#pragma once
#include"ADT_map.h"
#include<stack>
#include<vector>
#include<deque>
using namespace std;

template<typename T>
class map_matirx:public Graph
{
public:
	map_matirx(int num);
	~map_matirx();
	int n();
	int e();
	int first(int v);
	int next(int v, int w);
	bool setPoint(int v, T val);
	bool setEdge(int v1, int v2, int wght);
	bool delEdge(int v1, int v2);
	bool isEdge(int i, int j);
	int weight(int v1, int v2);
	bool setMark(int v, bool val);
	bool getMark(int v);
	int findPoint(T v);
	T getPoint(int v);
	void reset_mark();
	vector<T> BFS(int n);
private:
	int numPoint, numEdge;
	T* point;
	bool* mark;
	int** matirx;
};

template<typename T>
map_matirx<T>::map_matirx(int num)
{
	point = new T[num];

	matirx = new int* [num];
	for (int i = 0; i < num; i++)
		matirx[i] = new int[num];
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			matirx[i][j] = 0;

	numPoint = num;
	numEdge = 0;

	mark = new bool[num];
	for (int i = 0; i < num; i++)
		mark[i] = false;
}

template<typename T>
map_matirx<T>::~map_matirx()
{
	for (int i = 0; i < numPoint; i++)
		delete[]matirx[i];
	delete[]matirx;
	delete[]point;
	delete[]mark;
}

template<typename T>
inline int map_matirx<T>::n()
{
	return numPoint;
}

template<typename T>
inline int map_matirx<T>::e()
{
	return numEdge;
}

template<typename T>
int map_matirx<T>::first(int v)
{
	for (int i = 0; i < numPoint; i++)
		if (matirx[v][i] != 0)
			return i;
	return numPoint;
}

template<typename T>
int map_matirx<T>::next(int v, int w)
{
	for (int i = w + 1; i < numPoint; i++)
		if (matirx[v][i] != 0)
			return i;
	return numPoint;
}

template<typename T>
inline bool map_matirx<T>::setPoint(int v, T val)
{
	if (v < numPoint)
	{
		point[v] = val;
		return true;
	}
	else
		return false;
}

template<typename T>
inline bool map_matirx<T>::setEdge(int v1, int v2, int wght)
{
	if (matirx[v1][v2] != 0 || wght <= 0 || v1 >= numPoint || v2 >= numPoint)
		return false;
	else
	{
		matirx[v1][v2] = wght;
		numEdge++;
		return true;
	}
}

template<typename T>
inline bool map_matirx<T>::delEdge(int v1, int v2)
{
	if (v1 >= numPoint || v2 >= numPoint || matirx[v1][v2] == 0)
		return false;
	else
	{
		matirx[v1][v2] = 0;
		numEdge--;
		return true;
	}
}

template<typename T>
inline bool map_matirx<T>::isEdge(int i, int j)
{
	if (i < numPoint && j < numPoint && matirx[i][j] != 0)
		return true;
	else
		return false;
}

template<typename T>
inline int map_matirx<T>::weight(int v1, int v2)
{
	if (v1 < numPoint && v2 < numPoint)
		return matirx[v1][v2];
	else
		return 0;
}

template<typename T>
inline bool map_matirx<T>::setMark(int v, bool val)
{
	if (v < numPoint)
	{
		mark[v] = val;
		return true;
	}
	else
		return false;
}

template<typename T>
inline bool map_matirx<T>::getMark(int v)
{
	return mark[v];
}

template<typename T>
int map_matirx<T>::findPoint(T val)
{
	for (int i = 0; i < numPoint; i++)
	{
		if (point[i] == val)
			return i;
	}
	return -1;
}

template<typename T>
inline T map_matirx<T>::getPoint(int v)
{
	return point[v];
}

template<typename T>
void map_matirx<T>::reset_mark()
{
	for (int i = 0; i < numPoint; i++)
		mark[i] = false;
}

template<typename T>
vector<T> map_matirx<T>::BFS(int i)
{
	deque<T> que;
	vector<T> l;
	setMark(i, true);
	que.push_back(getPoint(i));
	l.push_back(getPoint(i));
	int v;
	while (!que.empty())
	{
		v = que.back() - 1;
		que.pop_back();
		for (int i = first(v); i < numPoint; i = next(v, i))
		{
			if (getMark(i) == false)
			{
				setMark(i, true);
				que.push_back(getPoint(i));
				l.push_back(getPoint(i));
			}
		}
	}
	return l;
}

