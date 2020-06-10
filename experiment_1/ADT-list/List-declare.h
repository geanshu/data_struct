#pragma once
template<typename T>
class ADTList
{
public:
	ADTList() {};
	virtual bool insert(int pos, T n)=0;
	virtual bool push_back(T n)=0;
	virtual bool change_value(int pos, T n)=0;
	virtual bool earse(int pos)=0;
	virtual int get_size()=0;
	virtual T get_value(int pos)=0;
	virtual bool clear()=0;
	~ADTList() {};
};