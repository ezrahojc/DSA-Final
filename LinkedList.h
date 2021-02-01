#pragma once
// Assignment #1
// File: LinkedList.h
// Name: Ezra Ho Jincheng

#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings

using namespace std;

//struct Project represents some project information
struct Node
{
    int songID;
    string songName;
    string songArtist;
    string songGenre;
    double songDuration;
    Node* next;
};

class LinkedList
{
private:
    Node* firstNode;

public:
    LinkedList();
    ~LinkedList();

    bool add(int songID, string songName, string songArtist, string songGenre, double songDuration);
    bool remove(int songID);

    void printList();
};
