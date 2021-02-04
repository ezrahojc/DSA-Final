//Hannah Leong
//Stack.h
#pragma once
#include <iostream>
using namespace std;

typedef string ItemType;

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
