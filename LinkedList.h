#pragma once
// Assignment #1
// File: LinkedList.h
// Name: Ezra Ho Jincheng

#include <iostream> //to use cout.
#include <iomanip> //to format output.
#include <string> //to use strings.
#include "Song.h"

using namespace std;

typedef Song ItemType;

//struct Project represents some project information

class LinkedList
{
private:
    struct Node
    {
        ItemType item;  // data item
        Node* next;     // pointer pointing to next item
        Node* previous; // Doubly Linked List Implementation
    };
    Node* firstNode;    // point to the first item
    Node* lastNode;     // point to the last item   
    int  size;			// number of items in the list

public:
    LinkedList();

    ~LinkedList();

    // add an item to the back of the list (append)
    // pre : size < MAX_SIZE
    // post: item is added to the back of the list
    //       size of list is increased by 1
    bool add(ItemType item);

    // remove an item at a specified position in the list
    // pre : 0 <= index < size
    // post: item is removed the specified position in the list
    //       items after the position are shifted forward by 1 position
    //       size of list is decreased by 1
    bool remove(int index);

    // display the items in the list
    void printList();

    // get the items in the list
    bool get(int index);

    // Name: Ezra Ho Jincheng
    // Advanced Data Structure: Doubly Linked List Implementation
    void forward_traverse();

    // Name: Ezra Ho Jincheng
    // Advanced Data Structure: Doubly Linked List Implementation
    void backward_traverse(); 

    // check if the list is empty
    // pre : none
    // post: none
    // return true if the list is empty; otherwise returns false
    bool isEmpty();
};
