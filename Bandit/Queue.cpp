#include "Queue.h"


Queue::Queue(int m) 
{
	queue = new int[m];
	length = 0;
}

Queue::Queue(const Queue& other)
{
	this->length = other.length;
	this->maxLength = other.maxLength;

	if (queue != nullptr)
		delete[] queue;

	queue = new int[maxLength];

	for (int i = 0; i < length; i++)
	{
		queue[i] = other.queue[i];
	}
}

void Queue::clear()
{
	length = 0;
}

Queue::~Queue()
{
	if (queue != nullptr)
		delete[] queue;
}

void Queue::addElem(int elem)
{
	if (!isFull())
		queue[length++] = elem;

	else cout << "Queue is full!" << endl;
}

int Queue::extractElem()
{
	if (!isEmpty())
	{
		int temp = queue[0];
		this->length--;
		for (int i = 0; i < this->length; i++)
		{
			queue[i] = queue[i + 1];
		}
		return temp;
	}
	else
	{
		cout << "Queue is empty!" << endl;
		return -1;
	}
}

bool Queue::isEmpty() const
{
	return length == 0;
}

bool Queue::isFull() const
{
	return length == maxLength;
}

int Queue::getCount() const
{
	return length;
}

void Queue::printQueue() const
{
	for (int i = 0; i < length; i++)
	{
		cout << i + 1 << " " << queue[i] << endl;
	}
}

