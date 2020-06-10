#pragma once
template<typename T>
class List
{
public:
	List(int size);
	bool insert(int pos,T n);
	bool append(T n);
	bool change_value(int pos, T n);
	bool earse(int pos);
	int get_size();
	T get_value(int pos);
	bool clear();
	~List();
private:
	T* ListArray;
	int list_size;
	int max_size;
};