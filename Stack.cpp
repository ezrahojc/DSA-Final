//Hannah Leong
//Stack.cpp
#include "Stack.h"

Stack::Stack() { topNode = NULL; }
Stack::~Stack() {}

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
			cout << item << endl;		// display the item
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
			cout << item << endl;
			push(item);
			tempStack.pop();
		}
	}
	else
		cout << "The stack is empty." << endl;
}