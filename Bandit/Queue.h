#pragma once
#include <iostream>
using namespace std;

class Queue
{
protected:
	int* queue = nullptr;
	int maxLength = 0;
	int length = 0;

public:
	Queue()
	{
		maxLength = 5;
		queue = new int[maxLength];
		length = 0;
	}
	// ctor
	Queue(int m);
	Queue(const Queue& other);
	// clear queue
	void clear();
	// dctor
	~Queue();
	// add elem to queue
	void addElem(int elem);
	// extract elem
	int extractElem();
	// is empty
	bool isEmpty()const;
	// is full
	bool isFull()const;
	// element count
	int getCount()const;
	// print queue
	void printQueue()const;
};

