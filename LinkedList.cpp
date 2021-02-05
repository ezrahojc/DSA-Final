// Assignment #1
// File: LinkedList.cpp
// Name: Ezra Ho Jincheng

#include <iostream> //to use cout.
#include <iomanip> //to format output.
#include <string> //to use strings.
#include "LinkedList.h"
#include "Song.h"

using namespace std;

// brief Construct a new Linked List:: Linked List object.
LinkedList::LinkedList()
{
    firstNode = NULL;
    size = 0;
}

// brief Destroy the Linked List::Linked List object.
LinkedList::~LinkedList()
{
    
}

// Name: Ezra Ho Jincheng.
/* Function: Attempts to add the song and the parameters. If the user inputs the same song ID and song name and song artist, the program will return 0.
*            This is because some songs have the same same song name. Hence, ensuring that all 3 key parameters do not overlap is the most important
*            factor to ensuring that each song is only saved once in the linked list. */
// Algorithm Included: Search.
// Input Parameters: song ID (sID), song name (sN), song artist (sA), song genre (sG), song duration (sD).
// Return Value: Returns true / false.
bool LinkedList::add(ItemType new_data)
{
    // create a new node to store the item
    Node* newNode = new Node;
    newNode->item = new_data;
    newNode->next = NULL;

    if (isEmpty())
        firstNode = newNode;
    else
    {
        Node* temp = firstNode;
        while (temp->next != NULL)
        {
            
            temp = temp->next;      // move to last node
        }
        temp->next = newNode;		// make last node point to the new node
                                    // temp is to store how many places the list needs to jump to store the new value in the list
    }
    size++;

    return true;  // no size constraint
}

// Name: Ezra Ho Jincheng.
/* Function: It attempts to remove the song with the parameter song ID (sID).
*            Only returns true if it finds and removes song and attributes from linked list.
*            Otherwise, it returns false. */
// Algorithms Included: Search and Delete.
// Input Parameter: song ID (sID).
// Return Value: Returns true / false.
bool LinkedList::remove(int index)
{
    bool success = (index >= 0) && (index <= size);
    if (success)
    {
        if (index == 0) // remove front node
        {
            Node* temp = firstNode;
            firstNode = firstNode->next;
            delete temp;
        }
        else
        {
            Node* current = firstNode;
            Node* previous = firstNode;

            for (int i = 0; i < index; i++)
            {
                if (current->item.getSongId() == index) // compare the song ID user input and the one to be deleted
                {
                    previous->next = current->next;
                    delete current;
                    return 0;
                }
                previous = current;          // previous will always be one node behind current
                current = current->next;	 // move to next node
            }
        }
        size--;  // decrease the size of the list by 1
    }
    return 0;
}

// Name: Ezra Ho Jincheng.
/* Function: Print all the entries in the linked list in the format of 
*            "song ID, song name, song artist, song genre, song duration". */
// Input Parameter: none.
// Return Value: song ID, song name, song artist, song genre, song duration.
void LinkedList::printList()
{
    Node* temp = firstNode;

    if (temp != NULL)		// list is NOT empty
    {
        while (temp != NULL)
        {
            cout << "\nSong ID: " << temp->item.getSongId() << "\t || Song Name: " << temp->item.getTitle() << 
                "\t || Song Artist: " << temp->item.getArtist() << "\t || Song Genre: " << temp->item.getGenre()  << 
                "\t || Song Duration: " << temp->item.getLength()  << endl;
            temp = temp->next;
        }
    }
    else   // list is empty
    {
        cout << "The list is empty. Please enter a song into the song library." << endl;
    }
}

// do this
bool LinkedList::get(int index)
{
    Node* current = firstNode;
    bool success = (index >= 0) && (index < size);
    if (success)
    {
        if (current == NULL)
        {
            cout << "The song library is empty.\n";
        }
        else
        {
            if (current->item.getSongId() == index)
            {
                cout << "Song ID: " << current->item.getSongId() << ", " << "Song Name: " << current->item.getTitle() << ", "
                    << "Song Artist: " << current->item.getArtist() << ", " << "Song Genre: " << current->item.getGenre() << ", "
                    << "Song Duration: " << current->item.getLength() << " min" << endl;
            }
        }
    }
    return true;
}

bool LinkedList::isEmpty()
{
    return size == 0;
}