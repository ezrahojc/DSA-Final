//Hannah Leong
//Stack.cpp
#include "Stack.h"
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
			getTop(item);			// get the top item
			cout << "\nSong ID: " << item.getSongId() << " ," << "\nSong Name: " << item.getTitle() << 
				"\nSong Artist: " << item.getArtist() << "\nSong Genre: " << item.getGenre() << "\nSong Duration: " << item.getLength() << 
				"\nSong Description: " << item.getDescription() << "\nSong Album: " << item.getAlbum();	// display the item
			tempStack.push(item);		// save the item to tempStack
			pop();						// remove the item from current stack
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
			cout << item.getSongId() << endl;
			cout << item.getTitle() << endl;
			cout << item.getArtist() << endl;
			cout << item.getGenre() << endl;
			cout << item.getLength() << endl;
			cout << item.getDescription() << endl;
			cout << item.getAlbum() << endl;
			push(item);
			tempStack.pop();
		}
	}
	else
		cout << "The stack is empty." << endl;
}

