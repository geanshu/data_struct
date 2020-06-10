#pragma once
#include"List-declare.h"
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
class Linklist:public ADTList<T>
{
public:
	Linklist();//innitialize a linklist
	bool push_back(T a);//push char to the end of this linkllist
	bool insert(int n, T a);//insert char to position==n
	bool change_value(int pos, T n);
	void earse() {};
	Link<T>* earse(int n);//delete the link located in position==n
	Link<T>* get_head();//return head of this linklist
	Link<T>* get_tail();//return tail of this linklist
	T get_value(int pos);
	int get_size();//return the size of this linklist
	bool clear();//return list to initialization
	~Linklist();
	void sort();
	void swap(Link<T>* p, Link<T>* q);
private:
	Link<T>* head;
	Link<T>* tail;
	int listsize;
};

template<typename T>
inline Link<T>::Link()
{
	value = '\0';
	pre = NULL;
	next = NULL;
}

template<typename T>
inline Link<T>::Link(T a)
{
	value = a;
	pre = NULL;
	next = NULL;
}

template<typename T>
inline void Link<T>::putchar(T a)
{
	value = a;
}

template<typename T>
inline void Link<T>::linknext(Link* nextval)
{
	next = nextval;
}

template<typename T>
inline void Link<T>::linkpre(Link* preval)
{
	pre = preval;
}

template<typename T>
inline Link<T>* Link<T>::getnext()
{
	return next;
}

template<typename T>
inline Link<T>* Link<T>::getpre()
{
	return pre;
}

template<typename T>
inline T Link<T>::getval()
{
	return value;
}

template<typename T>
inline Linklist<T>::Linklist()
{
	head = new Link<T>;
	tail = new Link<T>;
	tail->linkpre(head);
	head->linknext(tail);
	listsize = 0;
}

template<typename T>
inline bool Linklist<T>::push_back(T a)
{

	if (listsize == 0)
	{
		head->putchar(a);
		listsize++;
		return true;
	}
	else
	{
		Link<T>* temp = new Link<T>(a);
		temp->linkpre(tail->getpre());
		(tail->getpre())->linknext(temp);
		temp->linknext(tail);
		tail->linkpre(temp);
		listsize++;
		return true;
	}
	return false;
}

template<typename T>
bool Linklist<T>::insert(int n, T a)
{
	if (n >= listsize)
	{
		return false;
	}
	Link<T>* temp = new Link<T>(a);
	if (listsize == 0)
	{
		head->putchar(a);
		listsize++;
		return true;
	}
	if (n == listsize - 1)
	{
		push_back(a);
		return true;
	}
	else if (n == 0)
	{
		temp->linknext(head);
		head->linkpre(temp);
		temp->linkpre(NULL);
		head = temp;
		listsize++;
		return true;
	}
	else
	{
		Link<T>* p = head;
		for (int i = 0; i < listsize; i++, p = (p->getnext()))
		{
			if (i == n)
			{
				temp->linkpre(p->getpre());
				(p->getpre())->linknext(temp);
				temp->linknext(p);
				p->linkpre(temp);
				listsize++;
				break;
			}
		}
		return true;
	}
}

template<typename T>
inline bool Linklist<T>::change_value(int pos, T n)
{
	int i = 0;
	for (Link<T>* it = head; it != tail; it = it->getnext(), i++)
	{
		if (i == pos)
		{
			it->putchar(n);
			return true;
		}
	}
	return false;
}

template<typename T>
Link<T>* Linklist<T>::earse(int n)
{
	if (listsize == 0)
	{
		std::cout << "linklist is null" << std::endl;
		return head;
	}

	if (n == 0)
	{
		Link<T>* temp = head;
		head = head->getnext();
		head->linkpre(NULL);
		delete temp;
		listsize--;
		return head;
	}
	else
	{
		int i = 0;
		for (Link<T>* temp = head; temp->getnext() != NULL; temp = temp->getnext(), i++)
		{
			if (i == n)
			{
				(temp->getpre())->linknext(temp->getnext());
				(temp->getnext())->linkpre(temp->getpre());
				listsize--;
				return temp->getnext();
			}
		}
	}
	return NULL;
}

template<typename T>
inline Link<T>* Linklist<T>::get_head()
{
	return head;
}

template<typename T>
inline Link<T>* Linklist<T>::get_tail()
{
	return tail;
}

template<typename T>
T Linklist<T>::get_value(int pos)
{
	int i = 0;
	for (Link<T>* it = head; it != tail; it = it->getnext(), i++)
	{
		if (i == pos)
			return it->getval();
	}
}

template<typename T>
inline int Linklist<T>::get_size()
{
	return listsize;
}

template<typename T>
bool Linklist<T>::clear()
{
	for (int i = 0; i < listsize; i++)
		earse(0);
	return true;
}

template<typename T>
Linklist<T>::~Linklist()
{
	clear();
	if (head == tail)
		delete head;
	else
	{
		delete tail;
		delete head;
	}
}

template<typename T>
void Linklist<T>::sort()
{
	for (Link<T>* p = head; p != tail->getpre(); p = p->getnext())
	{
		for (Link<T>* q = p->getnext(); q != tail; q = q->getnext())
		{
			if (p->getval() > q->getval())
			{
				swap(p, q);
			}
		}
	}
}

template<typename T>
inline void Linklist<T>::swap(Link<T>* p, Link<T>* q)
{
	T temp = p->getval();
	p->putchar(q->getval());
	q->putchar(temp);
}
