// Main file.
// Program execution begins and ends here.

#include <iostream>
#include <string>
#include "Song.h"
#include "Playlist.h"
#include "LinkedList.h"
using namespace std;

bool success = false;
string addSong, addArtist, addGenre;
int addSID, addDuration;
void callMenu();

int main()
{
    // linked list that contains the songs.
    LinkedList* list1 = new LinkedList;

    // infinite loop until exit.
    bool x = true;
    while (x == true)
    {
        callMenu();
        int a;
        cout << "\nPlease choose a choice: ";

        while (!(cin >> a)) // validation to ensure only numbers
        {
            cout << "\nInvalid choice, please enter a valid choice: ";
            cin.clear();
            while (cin.get() != '\n'); // empty loop
        } // works

        // Name: Ezra Ho Jincheng.
        // Function: allows the user to input the details and parameters of the song.
        // Input Parameters: addSID, addSong, addArtist, addGenre, addDuration.
        // Output Parameters: a cout showing indicating that the song has been saved / has not been saved.
        // no input validation yet
        if (a == 1)
        {
            cout << "\n == Add Songs == \n";
            cout << "\nPlease enter the song ID: ";
            while (!(cin >> addSID) || addSID <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song ID integer: ";
            }
            

            cout << "\nPlease enter the song name: ";
            cin.ignore(); // clear one or more characters from input buffer.
            getline(cin, addSong); // ensure that the whole line can be captured as input.
            
            cout << "\nPlease enter the song artist: ";
            getline(cin, addArtist);

            cout << "\nPlease enter the song genre: ";
            getline(cin, addGenre);

            cout << "\nPlease enter the song duration: ";
            while (!(cin >> addDuration) || addDuration <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song duration integer: ";
            }

            success = list1->add(addSID, addSong, addArtist, addGenre, addDuration); // add the song attributes into the list.

            if (success == true)
            {
                cout << "The song '" << addSong << "' and attributes were added.\n";
            }
            else
            {
                cout << "The song '" << addSong << "' and attributes were not added. There is already a similarly named song ID and song name in the list.\n";
            }
        }

        // Name: Ezra Ho Jincheng.
        // Function: prints the list of songs saved in the linked list data structure.
        // Input Parameters: none.
        // Output Parameters: none.
        else if (a == 2)
        {
            cout << "\n == Display Songs == \n";
            list1->printList();
        }

        // Name: Ezra Ho Jincheng.
        // Function: allows the user to remove the song just by using the song ID keyed in by the user.
        // Input Parameters: addSID.
        // Output Parameters: a cout showing indicating that the song has been deleted / has not been deleted since the song does not exist.
        // no validation yet.
        else if (a == 3)
        {
            cout << "\n == Remove Song == \n";
            cout << "Please enter ID of song to be removed: ";
            while (!(cin >> addSID) || addSID <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song ID integer: ";
            }

            success = list1->remove(addSID);
            if (success == true)
            {
                cout << "Song ID '" << addSID << "' removed.\n";
            }
            else
            {
                cout << "Song ID '" << addSID << "' does not exist.\n";
            }
        }

        else if (a == 4)
        {
            cout << "\n == Add song to playlist queue == \n";

        }

        else if (a == 5)
        {
            cout << "\n == Remove song from playlist queue == \n";

        }

        else if (a == 0)
        {
            cout << "Exiting... \n\n";
            break;
        }
    }
}

// Name: Ezra Ho Jincheng.
// Function: callMenu() function is used to print the menu at the start and a choice has been fully performed by the user.
// Input Parameters: none
// Output Parameters: none
void callMenu()
{
    cout << "\n======\t======\n";
    cout << "Choice\tAction\n";
    cout << "======\t======\n";
    cout << "1\tAdd song\n";
    cout << "2\tDisplay songs\n";
    cout << "3\tRemove songs\n";
    cout << "4\tAdd songs to playlist queue\n";
    cout << "5\tRemove songs to playlist queue\n";
    cout << "0\tQuit\n";
}