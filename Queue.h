#pragma once
// Queue.h - Specification of Queue ADT (Pointer-based)
#pragma once
#include <iostream>   
#include "Song.h"
using namespace std;

typedef Song ItemType;

class Queue
{
private:
	struct Node
	{
		ItemType item;		// to store data
		Node* next;		// to point to next node
	};

	Node* frontNode;		// to point to the front node
	Node* backNode;			// to point to the back node

public:
	
	// Work in progress

	//Queue();
	//~Queue();

	//// enqueue item at back of the queue
	//bool enqueue(ItemType item);

	//// dequeue item from front of the queue
	//bool dequeue();
	//bool dequeue(ItemType& item);

	//// retrieve item from front of queue
	//void getFront(ItemType& item);

	//// check if the queue is empty
	//bool isEmpty();

	//// return the length of the queue
	//int getLength();

	//// display the items in the queue
	// void print();
};

