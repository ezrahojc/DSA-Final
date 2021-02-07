//Hannah Leong

// Stack.cpp - Implementation of Stack ADT (Pointer-based)


#include "Stack.h"
#include <iostream> //to use cout.
#include <iomanip> //to format output.
#include <string> //to use strings.
#include "Song.h"

// Construct a stack object
Stack::Stack() { topNode = NULL; }

// Destructor to delete items from stack
Stack::~Stack() 
{
	Node* temp;
	while (topNode != NULL)
	{
		temp = topNode;
		topNode = topNode->next;

		delete temp;
	}
}

bool Stack::isEmpty()
{
	return (topNode == NULL);
}

// Name: Hannah Leong Jia Wen.
// Function: Adds song into the stack
// Algorithm Included: Insert.
// Input Parameters: none.
// Return Value: Returns true / false.
bool Stack::push(ItemType item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = topNode;
	topNode = newNode;
	return true;
}

// Name: Hannah Leong Jia Wen.
// Function: Removes song from the stack
// Algorithm Included: Delete.
// Input Parameters: none.
// Return Value: Returns true / false.
bool Stack::pop()
{
	bool success = !isEmpty();
	if (success) {
		Node* temp = topNode;
		topNode = topNode->next;
		temp->next = NULL;
		delete temp;
		temp = NULL;
	}
	return success;
}

bool Stack::pop(ItemType& item)
{
	bool success = !isEmpty();
	if (success) {
		item = topNode->item;
		return pop();
	}
}

// Name: Hannah Leong Jia Wen.
// Function: Gets song from the top of the stack
// Algorithm Included: 
// Input Parameters: none.
// Return Value: Returns true / false.
void Stack::getTop(ItemType& item)
{
	bool success = !isEmpty();
	if (success)
		item = topNode->item;
}

// Name: Hannah Leong Jia Wen.
// Function: Displays items in stack order
// Algorithm Included:
// Input Parameters: none.
void Stack::displayInOrder()
{
	ItemType item;
	Stack tempStack;
	if (!isEmpty())
	{
		// put items into reversed order and display the stack items
		while (!isEmpty())
		{
			getTop(item);			                // get the top item
			// display the item
			cout << "\n\nSong ID: " << item.getSongId() << "\nSong Name: " << item.getTitle() <<
				"\nSong Artist: " << item.getArtist() << "\nSong Genre: " << item.getGenre() <<
				"\nSong Duration: " << item.getLength() << " min" << "\nSong Description: " << 
				item.getDescription() << "\nSong Album: " << item.getAlbum() << endl;
			tempStack.push(item);		            // save the item to tempStack
			pop();						            // remove the item from current stack
		}
		// restore the original stack
		while (!tempStack.isEmpty())
		{
			tempStack.getTop(item);
			push(item);
			tempStack.pop();
		}
	}
	else
		cout << "Search History is Empty." << endl;
}


