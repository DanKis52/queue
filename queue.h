#pragma once
class Customer
{
public:
	Customer() { arrive = processTime = 0; }
	void set(long when);
	long when() const { return arrive; }
	int ptime() const { return processTime; }
private:
	long arrive;
	int processTime;
};

typedef Customer Item;

class Queue
{
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	int queueCount() const;
	bool enQueue(const Item& item);
	bool deQueue(Item& item);

private:
	enum {Q_SIZE = 10};
	struct Node
	{
		Item item;
		struct Node* next;
	};

	Node* front;
	Node* rear;
	int items;
	const int qsize;

	// ”преждающие объ€влени€ дл€ предотвращени€ открытого копировани€
	//Queue(const Queue& q) : qsize(0) {}
	Queue& operator=(const Queue& q) { return *this; }
};
