#pragma once
template<typename T>
class Link
{
private:
	T value;
	Link* next;
	Link* pre;
public:
	Link();
	Link(T a);
	void putchar(T a);
	void linknext(Link* nextval = NULL);
	void linkpre(Link* preval = NULL);
	Link<T>* getnext();
	Link<T>* getpre();
	T getval();
};

template<typename T>
class Linklist
{
public:
	Linklist();//innitialize a linklist
	bool push_back(T a);//push char to the end of this linkllist
	bool insert(int n, T a);//insert char to position==n
	Link<T>* earse(int n);//delete the link located in position==n
	Link<T>* get_head();//return head of this linklist
	Link<T>* get_tail();//return tail of this linklist
	int get_size();//return the size of this linklist
	void removeall();//return list to initialization
	~Linklist();
private:
	Link<T>* head;
	Link<T>* tail;
	int listsize;
};

