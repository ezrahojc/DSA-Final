// Main file
// Program execution begins and ends here

#include <iostream>
#include <string>
#include "Songs.h"
#include "Playlist.h"
#include "LinkedList.h"
using namespace std;

bool success = false;
string addSong, addArtist, addGenre;
int addSID;
double addDuration;
void callMenu();

int main()
{
    LinkedList* list1 = new LinkedList;

    bool x = true;
    while (x == true)
    {
        callMenu();
        int a;
        cout << "\nPlease choose a number: ";
        cin >> a;

        if (a == 1)
        {
            cout << "\n == Add Songs == \n";
            cout << "Please enter the song ID: ";
            cin >>  addSID;

            cout << "\n\nPlease enter the song name: ";
            cin.ignore();
            getline(cin,addSong);

            cout << "\n\nPlease enter the song artist: ";
            getline(cin,addArtist);

            cout << "\n\nPlease enter the song genre: ";
            getline(cin,addGenre);

            cout << "\n\nPlease enter the song duration: ";
            cin >> addDuration;

            success = list1->add(addSID, addSong, addArtist, addGenre, addDuration);

            if (success == true)
            {
                cout << "The song '" << addSong << "' and attributes were added.\n";
            }
            else
            {
                cout << "The song '" << addSong << "' and attributes were not added. There is already a similarly named project in the list.\n";
            }
        }

        else if (a == 2)
        {
            cout << "\n == Display Songs == \n";
            list1->printList();
        }

        else if (a == 3)
        {
            cout << "\n == Remove Songs == \n";
            cout << "Please enter a song ID to remove: ";
            cin >> addSID;

            success = list1->remove(addSID);
            if (success == true)
            {
                cout << "The song ID '" << addSID << "' removed.\n";
            }
            else
            {
                cout << "The song ID '" << addSID << "' does not exist.\n";
            }
        }

        else if (a == 4)
        {
            cout << "\n == Add songs to playlist queue == \n";

        }

        else if (a == 5)
        {
            cout << "\n == Remove songs to playlist queue == \n";

        }

        else if (a == 0)
        {
            cout << "Exiting... \n\n";
            break;
        }

        else
        {
            cout << "Incorrect input. Please try again.\n";
            exit;
        }

    }
}

void callMenu()
{
    cout << "\nChoice\tAction\n";
    cout << "------\t------\n";
    cout << "1\tAdd song\n";
    cout << "2\tDisplay songs\n";
    cout << "3\tRemove songs\n";
    cout << "4\tAdd songs to playlist queue\n";
    cout << "5\tRemove songs to playlist queue\n";
    cout << "0\tQuit\n";
}