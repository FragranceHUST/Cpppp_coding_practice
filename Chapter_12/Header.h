#pragma once
class Queue
{
	enum 
	{
		Q_SIZE = 10
	};

	struct Node	 
	{
		Item item;
		struct Node * next;
	};
public:
	Queue(int qsize = Q_SIZE);
	~Queue();
	bool insert(const Item &item);
	bool remove(Item &item);
	bool empty();
	bool full();
	int queueCount();
private:
	Queue(const Queue &q) : max_len(0) {}
	Queue & operator=(const Queue &q) { return *this; }
private:
	int len;			
	const int max_len;
	Node * front;
	Node * rear;
};