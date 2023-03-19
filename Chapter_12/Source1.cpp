#include "Header.h"
#include <iostream>
Queue::Queue(int qsize) : max_len(qsize)
{
	front = rear = nullptr;
	len = 0;
}

Queue::~Queue()
{
	Node* temp;
	while (front != nullptr)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	if (rear != nullptr)
	{
		delete rear;
		rear = nullptr;
	}
}

bool Queue::empty()
{
	return len == 0;
}

bool Queue::full()
{
	return len == max_len;
}

int Queue::queueCount()
{
	return len;
}

bool Queue::insert(const Item &item)
{
	if (full())
	{
		return false;
	}

	Node* add = new Node;
	if (!add)
	{
		printf("alloc failure\n");
		return false;
	}
	add->item = item;
	add->next = nullptr;
	len++;
	if (front == nullptr)
	{
		front = add;
	}
	else
	{
		rear->next = add;
	}
	rear = add;
	return true;
}

bool Queue::remove(Item &item)
{
	if (front == nullptr)
	{
		return false;
	}

	item = front->item;
	len--;
	Node* temp = front;
	front = front->next;
	delete temp;
	if (len == 0)
	{
		rear = nullptr;
	}
	return true;
}