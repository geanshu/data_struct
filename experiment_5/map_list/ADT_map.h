#pragma once
class Graph
{
public:
	virtual int n() = 0;
	virtual int e() = 0;
	virtual int first(int v) = 0;
	virtual int next(int v, int w) = 0;
	virtual void setEdge(int v1, int v2, int wght) = 0;
	virtual bool delEdge(int v1, int v2) = 0;
	virtual bool isEdge(int v1, int v2) = 0;
	virtual int weight(int v1, int v2) = 0;
	virtual bool setMark(int v, bool val) = 0;
	virtual bool getMark(int v) = 0;
};