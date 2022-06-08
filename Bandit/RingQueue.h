#pragma once

#include "Queue.h"

class RingQueue : public Queue
{
public:
	RingQueue()
	{
		this->maxLength = 5;
		this->queue = new int[this->maxLength];
		this->length = 0;
	}
	// ctor
	RingQueue(int m);
	~RingQueue();
	RingQueue(const RingQueue& other);

	RingQueue& operator=(const RingQueue& other);

	// extract elem
	int extractElem();
};

