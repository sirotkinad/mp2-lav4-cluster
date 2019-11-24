#pragma once
#ifndef __QUEUE_H__
#define __QUEUE_H__
#include <iostream>
const int MaxSize = 10000;
using namespace std;
template <class T>
class Queue
{
	T* queuePtr;
	int size;  // размер очереди
	int top, bottom;     // последний элемент в очереди, первый элемент в очереди 
	int DataCounter; // всего элементов в очереди
public:
	Queue(int _size = 0);
	~Queue();
	T Pop();
	void Push(T elem);
	bool Empty();
	bool Full();
	T GetElem();
	int GetSize();
};

template <class T>
Queue<T>::Queue(int _size)
{
	if ((_size < 1) || (_size > MaxSize))
		throw "Incorrest data";
	size = _size;
	queuePtr = new T[size];
	bottom = 0;
	top = -1;
	DataCounter = 0;
}

template <class T>
Queue<T>::~Queue()
{
	delete[] queuePtr;
}

template<class T>
T Queue <T>::Pop()
{
	if (Empty())
		throw "Queue is empty";
	else
	{
		bottom = bottom++;
		DataCounter--;
		return  queuePtr[bottom];
	}
}

template <class T>
void Queue<T>::Push(T elem)
{
	if (Full())
		throw "Queue is full";
	else
	{
		top = top++;
		queuePtr[top] = elem;
		DataCounter++;
	}
}

template <class T>
bool Queue<T>::Empty()
{
	return DataCounter == 0;
}

template <class T>
bool Queue<T>::Full()
{
	return size == DataCounter;
}

template <class T>
int Queue<T>::GetSize()
{
	return DataCounter;
}

template <class T>
T Queue<T>::GetElem()
{
	return queuePtr[bottom];
}

#endif