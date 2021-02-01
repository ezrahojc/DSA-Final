// Assignment #1
// File: LinkedList.cpp
// Name: Ezra Ho Jincheng

#include <iostream> //to use cout.
#include <iomanip> //to format output.
#include <string> //to use strings.
#include "LinkedList.h"

using namespace std;


// brief Construct a new Linked List:: Linked List object.
LinkedList::LinkedList()
{
    firstNode = NULL;
}

// brief Destroy the Linked List:: Linked List object.
LinkedList::~LinkedList()
{
    int x = 0;
}

// Name: Ezra Ho Jincheng.
/* Function: Attempts to add the song and the parameters. If the user inputs the same song ID and song name and song artist, the program will return 0.
*            This is because some songs have the same same song name. Hence, ensuring that all 3 key parameters do not overlap is the most important
*            factor to ensuring that each song is only saved once in the linked list. */
// Algorithm Included: Search.
// Input Parameters: song ID (sID), song name (sN), song artist (sA), song genre (sG), song duration (sD).
// Return Value: Returns true / false.

bool LinkedList::add(int sID, string sN, string sA, string sG, double sD)
{
    // firstNode is passed by reference
    Node** current = &firstNode;
    
    while ((*current))// Find position in list
    {
        // match sID, sN and sA of the new song with those already inside the list
        if ((sID == (*current)->songID) && ((sN == (*current)->songName) <= 0) && ((sA == (*current)->songArtist) <= 0))
        {
            break;
        }
        current = &(*current)->next;
    }

    if ((*current) != NULL) // if memory of current is not NULL
    {
        if ((*current)->songID == sID) // Check for song ID w/ same ID
        {
            return 0;
        }
    }

    Node* newSong = new Node;
    if (newSong == 0) //check for memory error
    {
        return 0;
    }

    newSong->songID = sID;
    newSong->songName = sN;
    newSong->songArtist = sA;
    newSong->songGenre = sG;
    newSong->songDuration = sD;
    newSong->next = *current;
    *current = newSong;

    return 1;
}

// Name: Ezra Ho Jincheng.
/* Function: It attempts to remove the song with the parameter song ID (sID).
*            Only returns true if it finds and removes song and attributes from linked list.
*            Otherwise, it returns false. */
// Algorithms Included: Search and Delete.
// Input Parameter: song ID (sID).
// Return Value: Returns true / false.
bool LinkedList::remove(int sID)
{
    Node** curr = &firstNode;
    while ((*curr))
    {
        if ((*curr)->songID == sID) // search for the sID
        {
            Node* unlinked = (*curr); // remove link
            *curr = (*curr)->next; // current will link to the node after
            delete(unlinked); // delete the node
            return 1;
        }
        curr = &(*curr)->next;
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
    if (firstNode == NULL) {
        cout << "The list is empty. Please enter a song into the list of songs." << endl;
        return;
    }
    Node** current = &firstNode;
    for (; *current; current = &(*current)->next)
    {
        cout << "Song ID: " << (*current) -> songID << ", ";
        cout << "Song Name: " << (*current) -> songName << ", ";
        cout << "Song Artist: " << (*current) -> songArtist << ", ";
        cout << "Song Genre: " << (*current) -> songGenre << ", ";
        cout << "Song Duration: " << (*current) ->songDuration << endl;
    }
}