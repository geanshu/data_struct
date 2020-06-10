#pragma once
#include<list>
#include"ADT_map.h"
using namespace std;

class Edge
{
public:
	Edge() { vert = -1; wt = -1; };
	Edge(int v, int w) { vert = v; wt = w; };
	int vertex() { return vert; };
	int weight() { return wt; };
private:
	int vert, wt;
};

template<typename T>
class map_list :public Graph
{
public:
	map_list(int n);
	~map_list();
	int n();
	int e();
	int first(int v);
	int next(int v, int w);
	void setEdge(int v1, int v2, int wght);
	bool delEdge(int v1, int v2);
	bool isEdge(int v1, int v2);
	int weight(int v1, int v2);
	bool setMark(int v, bool val);
	bool getMark(int v);
	bool setPoint(int v, T val);
	int findPoint(T val);
	T getPoint(int i);
private:
	list<Edge>** vertex;
	int numPoint, numEdge;
	T* point;
	bool* mark;
};

template<typename T>
map_list<T>::map_list(int n)
{
	vertex = new list<Edge>*[n];
	numPoint = n;
	numEdge = 0;
	point = new T[n];
	mark = new bool[n];
	for (int i = 0; i < n; i++)
	{
		mark[i] = false;
		vertex[i] = new list<Edge>;
	}
}

template<typename T>
map_list<T>::~map_list()
{
	for (int i = 0; i < numPoint; i++)
	{
		delete vertex[i];
	}
	delete[]vertex;
	delete[]mark;
	delete[]point;
}

template<typename T>
inline int map_list<T>::n()
{
	return numPoint;
}

template<typename T>
inline int map_list<T>::e()
{
	return numEdge;
}

template<typename T>
inline int map_list<T>::first(int v)
{
	if ((vertex[v]->size() == 0))
		return numPoint;
	return vertex[v]->begin()->vertex();
}

template<typename T>
int map_list<T>::next(int v, int w)
{
	if ((int)vertex[v]->size() > w + 1)
	{
		list<Edge>::iterator it;
		for (it = vertex[v]->begin(); it != vertex[v]->end(); it++)
		{
			if ((*it).vertex() == w)
				break;
		}
		if (it != vertex[v]->end())
		{
			it++;
			if (it != vertex[v]->end())
				return (*it).vertex();
			else
				return numPoint;
		}
		else
			return numPoint;
	}
	else
		return numPoint;
}

template<typename T>
void map_list<T>::setEdge(int v1, int v2, int wght)
{
	vertex[v1]->push_back(Edge(v2, wght)); 
}

template<typename T>
bool map_list<T>::delEdge(int v1, int v2)
{
	if (vertex[v1]->size() == 0)
		return false;
	for (list<Edge>::iterator it = vertex[v1]->begin(); it != vertex[v1]->end(); it++)
	{
		if (it->vertex() == v2)
		{
			vertex[v1]->erase(it);
			return true;
		}	
	}
	return false;
}

template<typename T>
bool map_list<T>::isEdge(int v1, int v2)
{
	if (vertex[v1]->size() == 0)
		return false;
	for (list<Edge>::iterator it = vertex[v1]->begin(); it != vertex[v1]->end(); it++)
		if (it->vertex() == v2)
			return true;

	return false;
}

template<typename T>
int map_list<T>::weight(int v1, int v2)
{
	if (vertex[v1]->size() == 0)
		return numPoint;
	for (list<Edge>::iterator it = vertex[v1]->begin(); it != vertex[v1]->end(); it++)
	{
		if (it->vertex() == v2)
		{
			return it->weight();
		}
	}
	return numPoint;
}

template<typename T>
inline bool map_list<T>::setMark(int v, bool val)
{
	if (v >= numPoint)
		return false;
	mark[v] = val;
	return true;
}

template<typename T>
inline bool map_list<T>::getMark(int v)
{
	return mark[v];
}

template<typename T>
inline bool map_list<T>::setPoint(int v, T val)
{
	if (v >= numPoint)
		return false;
	point[v] = val;
	return true;
}

template<typename T>
int map_list<T>::findPoint(T val)
{
	for (int i = 0; i < numPoint; i++)
		if (point[i] == val)
			return i;
	return numPoint;
}

template<typename T>
inline T map_list<T>::getPoint(int i)
{
	return point[i];
}
