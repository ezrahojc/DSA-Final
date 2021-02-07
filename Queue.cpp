
// Matthias Gan

// Queue.cpp - Implementation of Queue ADT (Pointer-based)


#include "Queue.h"
#include <iostream> //to use cout.
#include <iomanip> //to format output.
#include <string> //to use strings.
#include "Song.h"

// Construct a new Queue:: Queue object
Queue::Queue()
{
	frontNode = NULL;
	backNode = NULL;
}

// Destroy queue by deallocating container memory
Queue::~Queue() { }

// Name: Matthias Gan
// Function: Attempts to add the song object to the queue
// Algorithm Included: Insert.
// Input Parameters: song object 
// Song objecct is obtained in main fuction by asking user for Song ID
// and then traversing list to retrieve song object
// Return Value: Returns true / false.
bool Queue::enqueue(const ItemType item)
{
	// create a new node to store data
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = NULL;

	// insert the new node
	if (isEmpty())								// enqueue at the front
	{
		frontNode = newNode;
		backNode = newNode;
	}

	else										// enqueue at the back
	{
		backNode->next = newNode;
		backNode = newNode;						// new node is at back
	}
	return true;
}


// Name: Matthias Gan
// Function: Attempts to remove the song object from the queue
// Algorithm Included: Delete
// Input Parameters: song object 
// Song objecct is obtained in main fuction by asking user for Song ID
// and then traversing list to retrieve song object
// Return Value: Returns true / false.
bool Queue::dequeue()
{
	bool success = !isEmpty();
	if (success)								// queue is not empty -> remove front
	{
		Node* temp = frontNode;					// to be returned to the system
		if (frontNode == backNode)				// only one node in the queue
		{
			frontNode = NULL;
			backNode = NULL;
		}
		else
		{
			frontNode = frontNode->next;
		}
			
		// return node to the system
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}
	return success;
}

// same as above
// overloaded function was renamed to force program to perform in
// particular sequence
bool Queue::dequeue2(int index)
{
	bool success = !isEmpty();
	if (success)								// queue is not empty
	{
		index = frontNode->item.getSongId();	// retrieve front item
		dequeue();								// delete front
	}

	return success;
}


// Name: Matthias Gan
// Function: Counts number of song objects in the queue
// Input Parameters: song object 
// Song objecct is obtained in main fuction by asking user for Song ID
// and then traversing list to retrieve song object
// Return Value: Returns count
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
// checks if the queue is empty
bool Queue::isEmpty() { return frontNode == NULL; }


// prints song objects in queue
void Queue::print()
{
	Node* temp = frontNode;

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



