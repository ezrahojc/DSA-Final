
// Matthias Gan

// Queue.cpp - Implementation of Queue ADT (Pointer-based)
// Work in progress

#include "Queue.h"
#include <iostream> //to use cout.
#include <iomanip> //to format output.
#include <string> //to use strings.
#include "Song.h"

Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

// Destroy queue by deallocating container memory
Queue::~Queue() { }

bool Queue::enqueue(const ItemType item)
{
	// create a new node to store data
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	// insert the new node
	if (isEmpty())	// enqueue at the front
	{
		frontNode = newNode;
		backNode = newNode;
	}
	else			// enqueue at the back
	{
		backNode->next = newNode;
		backNode = newNode;  // new node is at back
	}

	return true;
}

bool Queue::dequeue()
{
	bool success = !isEmpty();
	if (success)					// queue is not empty -> remove front
	{
		Node* temp = frontNode;		// to be returned to the system
		if (frontNode == backNode)  // only one node in the queue
		{
			frontNode = NULL;
			backNode = NULL;
		}
		else
			frontNode = frontNode->next;

		// return node to the system
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}

	return success;
}

bool Queue::dequeue(ItemType& item)
{
	bool success = !isEmpty();
	if (success)				// queue is not empty
	{
		item = frontNode->item; // retrieve front item
		dequeue();              // delete front
	}

	return success;
}

void Queue::getFront(ItemType& item)
{
	bool success = !isEmpty();
	if (success) // queue is not empty -> retrieve item at the front
		item = frontNode->item;
}

int Queue::getLength()
{
	Node* temp = frontNode;
	int count = 0;

	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}

	return count;
}

bool Queue::isEmpty() { return frontNode == NULL; }


void Queue::print()
{
	Node* temp = firstNode;

	if (temp != NULL)		// list is NOT empty
	{
		cout << "Songs in Queue:" << endl;

		while (temp != NULL)
		{
			cout << "\nSong ID: " << temp->item.getSongId() << "\t || Song Name: " << temp->item.getTitle() <<
				"\t || Song Artist: " << temp->item.getArtist() << "\t || Song Genre: " << temp->item.getGenre() <<
				"\t || Song Duration: " << temp->item.getLength() << endl;
			temp = temp->next;
		}
	}
	else   
	{
		cout << "The queue is empty" << endl;
	}
}

bool Queue::get(int index)
{
	Node* temp = frontNode;
	bool success = !isEmpty();
	if (success)
	{
		
		if (frontNode == backNode)  // only one node in the queue
		{
			frontNode = NULL;
			backNode = NULL;
			cout << "The song library is empty.\n"
		}
		else
		{
			if (temp->item.getSongId() == index)
			{
				cout << "Song ID: " << current->item.getSongId() << ", " << "Song Name: " << current->item.getTitle() << ", "
					<< "Song Artist: " << current->item.getArtist() << ", " << "Song Genre: " << current->item.getGenre() << ", "
					<< "Song Duration: " << current->item.getLength() << " min" << endl;
			}
		}
	}
	return true;
}



