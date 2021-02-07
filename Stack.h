//Hannah Leong
//Stack.h
#pragma once
#include <iostream>
#include "Song.h"
#include <iomanip> 
#include <string> 

using namespace std;

typedef Song ItemType;

class Stack {
private:
    struct Node {
        ItemType item;
        Node* next;
    };

    Node* topNode;

public:
    //constructor
    Stack();

    //destructor
    ~Stack();

    // check if the list is empty
    // pre : none
    // post: none
    // return true if the list is empty; otherwise returns false
    bool isEmpty();

    // push (add) item to the top of the stack
    bool push(ItemType item);

    // pop (remove) item from the top of the stack
    bool pop();
    bool pop(ItemType& item);

    // get item at the top of the stack
    void getTop(ItemType& item);

    // display items in stack in order from last added to first added
    void displayInOrder();

    // display items in stack in order from insertion (first added to last added)
    void displayInOrderOfInsertion();
};
