#include <iostream> //to use cout
#include <iomanip> //to format output
#include <string> //to use strings
#include "LinkedList.h"

using namespace std;


// brief Construct a new Linked List:: Linked List object

LinkedList::LinkedList()
{
    firstNode = NULL;
}

// brief Destroy the Linked List:: Linked List object

LinkedList::~LinkedList()
{
    int x = 0;
}

/**
 * @brief Attempts to add a new project data into the linked list using the parameter values - project name,
 *        and the number of participants. If there is no memory left to create a new object or if a project
 *        with the same project name already exists in the linked list, the function will return 0.
 *        Otherwise returns 1.
 *
 * @param newProjectName Name of the project to be added
 * @param newNumberOfParticipants Number of participants
 * @return true
 * @return false
 */
bool LinkedList::add(int sID, string sN, string sA, string sG, double sD)
{
    Node** current = &firstNode;
    while ((*current))// Find pos. in list
    {
        if ((sN.compare((*current)->songName) <= 0)) // && (sA.compare((*current)->songArtist) <= 0) && (sG.compare((*current)->songGenre) <= 0))
        {
            break;
        }
        current = &(*current)->next;
    }

    if ((*current) != NULL)
    {
        if ((*current)->songID == sID) // Check for project w/ same name
        {
            return 0;
        }
    }

    Node* newSong = new Node;
    if (newSong == 0) //check for memory err
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

    //projectAddedMsg(newProjectName);
    return 1;
}//end method addProject

/**
 * @brief Attempts to remove the project with the parameter project name value.
 *        Returns true if it can find and remove the project information.
 *        Otherwise returns false.
 *
 * @param projectName Name of the project to be removed
 * @return true
 * @return false
 */
bool LinkedList::remove(int sID)
{
    Node** curr = &firstNode;
    while ((*curr))
    {
        if ((*curr)->songID == sID)
        {
            Node* unlinked = (*curr);
            *curr = (*curr)->next;
            delete(unlinked);
            return 1;
        }
        curr = &(*curr)->next;
    }
    return 0;
}

/**
 * @brief Prints all entries in the linked list in the following format:
 *       ' Project Name: projectName, Number of Participants: numberOfParticipants '
 */
void LinkedList::printList()
{
    if (firstNode == NULL) {
        cout << "The list is empty" << endl;
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
}//end method printList