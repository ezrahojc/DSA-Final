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
// Function: Attempts to add the song and the parameters
// Algorithm Included: Insert.
// Input Parameters: song ID, song name, song artist, song genre, song duration, song description, song album
// Return Value: Returns true / false.
bool LinkedList::add(ItemType new_data)
{
    // create a new node to store the item
    Node* newNode = new Node;
    newNode->next = NULL;
    newNode->item = new_data;
    if (isEmpty())
    {
        firstNode = newNode;
    }
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
    return true;                    // no size constraint
}

// Name: Ezra Ho Jincheng.
/* Function: It attempts to remove the song with the parameter song ID.
*            Only returns true if it finds and removes song and attributes from linked list.
*            Otherwise, it returns false. */
// Algorithms Included: Search and Delete.
// Input Parameter: song ID.
// Return Value: Returns true / false.
bool LinkedList::remove(int index)
{
    bool success = (index >= 0) && (index <= size);
    if (success)
    {
        if (index == 1)
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
                previous = current;                     // previous will always be one node behind current
                current = current->next;	            // move to next node
            }
        }
        size--;                                         // decrease the size of the list by 1
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
                "\t || Song Artist: " << temp->item.getArtist() << "\t || Song Genre: " << temp->item.getGenre() <<
                "\t || Song Duration: " << temp->item.getLength() << endl;
            temp = temp->next;
        }
    }
    else                    // list is empty
    {
        cout << "\nThe list is empty. Please enter a song into the song library." << endl;
    }
}

// Name: Ezra Ho Jincheng.
/* Function: Print all the entries in the linked list in the format of
*            "song ID, song name, song artist, song genre, song duration, song album, song duration, song album, song description". */
// Input Parameter: song ID.
// Return Value: song ID, song name, song artist, song genre, song duration, song album, song description, song album, song description.
ItemType LinkedList::get(int index)
{
    Node* current = firstNode;
    while (current != NULL)
    {
        if (current->item.getSongId() == index) // if the input user enter is the same as the song ID found within the song library, then get the item.
        {
            cout << "\nThe song ID found is :" << current->item.getSongId() << endl;
            cout << "\nThe following are the details of the song.";
            cout << "\nSong ID: " << current->item.getSongId() << "\nSong Name: " << current->item.getTitle() <<
                "\nSong Artist: " << current->item.getArtist() << "\nSong Genre: " << current->item.getGenre() <<
                "\nSong Duration: " << current->item.getLength() << " min" << "\nSong Album: " << current->item.getAlbum() <<
                "\nSong Description: " << current->item.getDescription() << endl;
            return current->item;

        }
        current = current->next;
    }
}

// Name: Ezra Ho Jincheng.
/* Function: Checks if the list is empty */
// Input Parameter: none.
// Return Value: 0.
bool LinkedList::isEmpty()
{
    return size == 0;
}