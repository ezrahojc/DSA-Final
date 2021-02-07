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

    // pushes an item to the top of the stack
    // pre:
    // post:
    // return true if successfully push
    bool push(ItemType item);

    // pops an item off the top of the stack
    // pre:
    // post:
    // return true if successfully pop
    bool pop();
    bool pop(ItemType& item);

    //
    void getTop(ItemType& item);

    // displays all items in the stack in order of last to first
    void displayInOrder();

    // displays all items in the stack in order of first to last
    void displayInOrderOfInsertion();
};
