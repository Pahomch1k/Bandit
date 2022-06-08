#include "RingQueue.h"

RingQueue::RingQueue(int m) :Queue(m) { }

RingQueue::~RingQueue()
{
	//if (this->queue != nullptr)delete[] this->queue;
}

RingQueue::RingQueue(const RingQueue& other)
{
	length = other.length;
	maxLength = other.maxLength;

	if (queue != nullptr)
		delete[] queue;

	queue = new int[maxLength];

	for (int i = 0; i < length; i++)
	{
		queue[i] = other.queue[i];
	}
}

RingQueue& RingQueue::operator=(const RingQueue& other)
{
	length = other.length;
	maxLength = other.maxLength;

	if (queue != nullptr)delete[] queue;

	queue = new int[maxLength];

	for (int i = 0; i < length; i++)
	{
		queue[i] = other.queue[i];
	}

	return *this;
}

int RingQueue::extractElem()
{
	if (!isEmpty())
	{
		int temp = queue[0];
		for (int i = 0; i < length - 1; i++)
		{
			queue[i] = queue[i + 1];
		}
		queue[length - 1] = temp;
		return temp;
	}
	else
	{
		cout << "Queue is empty!" << endl;
		return -1;
	}
}