//Hannah Leong

// Stack.cpp - Implementation of Stack ADT (Pointer-based)


#include "Stack.h"
#include <iostream> //to use cout.
#include <iomanip> //to format output.
#include <string> //to use strings.
#include "Song.h"


Stack::Stack() { topNode = NULL; }
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

bool Stack::push(ItemType item)
{
	Node* newNode = new Node;
	newNode->item = item;
	newNode->next = topNode;
	topNode = newNode;
	return true;
}

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

void Stack::getTop(ItemType& item)
{
	bool success = !isEmpty();
	if (success)
		item = topNode->item;
}

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
		cout << "The stack is empty." << endl;
}

void Stack::displayInOrderOfInsertion()
{
	ItemType item;
	Stack tempStack;

	if (!isEmpty())
	{
		// put items into reversed order and display the stack items
		while (!isEmpty())
		{
			getTop(item);
			tempStack.push(item);
			pop();
		}
		// restore the original stack
		while (!tempStack.isEmpty())
		{
			tempStack.getTop(item);
			cout << "\nThe song ID found is :" << item.getSongId() << endl;
			cout << "\nThe following are the details of the song.\n";
			cout << "\nSong ID: " << item.getSongId() << "\nSong Name: " << item.getTitle() <<
				"\nSong Artist: " << item.getArtist() << "\nSong Genre: " << item.getGenre() <<
				"\nSong Duration: " << item.getLength() << " min" << "\nSong Album: " << item.getAlbum() <<
				"\nSong Description: " << item.getDescription() << endl;
			push(item);
			tempStack.pop();
		}
	}
	else
		cout << "The stack is empty." << endl;
}

