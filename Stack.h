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
    Stack();
    ~Stack();
    bool isEmpty();
    bool push(ItemType item);
    bool pop();
    bool pop(ItemType& item);
    void getTop(ItemType& item);
    void displayInOrder();
    void displayInOrderOfInsertion();
};
