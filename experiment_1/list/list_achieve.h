#pragma once
#include"list_declare.h"

template<typename T>
inline List<T>::List(int size)
{
	max_size = size;
	list_size = 0;
	ListArray = new T[max_size];
}

template<typename T>
bool List<T>::insert(int pos, T n)
{
	if (pos < 0 || pos >= list_size)
		return false;
	for (int i = pos; i < list_size; i++)
		ListArray[i + 1] = ListArray[i];
	ListArray[pos] = n;
	list_size++;
	return true;
}

template<typename T>
inline bool List<T>::append(T n)
{
	if (list_size == max_size)
		return false;
	ListArray[list_size] = n;
	list_size++;
	return true;
}

template<typename T>
inline bool List<T>::change_value(int pos, T n)
{
	if (pos < 0 || pos >= list_size)
		return false;
	ListArray[pos] = n;
	return true;
}

template<typename T>
bool List<T>::earse(int pos)
{
	if (pos < 0 || pos >= list_size)
		return false;
	for (int i = pos; i < list_size-1; i++)
		ListArray[i] = ListArray[i + 1];
	ListArray[list_size - 1] = NULL;
	list_size--;
	return true;
}

template<typename T>
inline int List<T>::get_size()
{
	return list_size;
}

template<typename T>
inline T List<T>::get_value(int pos)
{
	return ListArray[pos];
}

template<typename T>
inline bool List<T>::clear()
{
	delete[]ListArray;
	list_size = 0;
	ListArray = new T[max_size];
	return true;
}

template<typename T>
inline List<T>::~List()
{
	delete [] ListArray;
}