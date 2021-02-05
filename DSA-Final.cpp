// This file contains 'main' functions.
// Program execution begins and ends here.

#include <iostream>
#include <string>
#include "Song.h"
#include "Playlist.h"
#include "LinkedList.h"
//#include "Queue.h"

using namespace std;

int main()
{
    bool success = false;
    string addSong, addArtist, addGenre;
    int addSID, addDuration;
    void callMenu();
    int i = 1;


    // linked list that contains the songs.
    LinkedList list1;

    // queue containing the song objects
    //Queue queue1;

    Song songID;
    // do running number for song ID

    // infinite loop until exit.
    bool x = true;
    while (x == true)
    {
        callMenu();
        int a;
        cout << "\nPlease choose a choice: ";
        cin >> a;
        while (!a || a < 0) // validation to ensure only numbers (users can still enter decimals)
        {
            cout << "\nInvalid choice, please enter a valid choice: ";
            cin.clear();
            cin.ignore(10000, '\n');
            cin >> a;
        }

        // Name: Ezra Ho Jincheng.
        // Function: allows the user to input the details and parameters of the song.
        // Input Parameters: addSong, addArtist, addGenre, addDuration.
        // Output Parameters: a cout showing indicating that the song has been saved / has not been saved.
        if (a == 1)
        {
            cout << "\n == Add Songs == \n";

            cout << "\nPlease enter the song name: ";
            cin.ignore(); // clear one or more characters from input buffer.
            getline(cin, addSong); // ensure that the whole line can be captured as input.
            while (addSong.empty())
            {
                cout << "\nInvalid input. Please enter a song name: ";
                cin.clear();
                getline(cin, addSong);
            }

            cout << "\nPlease enter the song artist: ";
            getline(cin, addArtist);
            while (addArtist.empty())
            {
                cout << "\nInvalid input. Please enter the song artist: ";
                cin.clear();
                getline(cin, addArtist);
            }

            cout << "\nPlease enter the song genre: ";
            getline(cin, addGenre);
            while (addGenre.empty())
            {
                cout << "\nInvalid input. Please enter the song genre: ";
                cin.clear();
                getline(cin, addGenre);
            }

            // users can still add decimal numbers
            cout << "\nPlease enter the song duration: ";
            while (!(cin >> addDuration) || addDuration <= 0)
            {
                cout << "\nPlease enter a valid song duration integer: ";
                cin.clear();
                cin.ignore();
            }

            songID.setSongId(i);
            i++;
            songID.setTitle(addSong);
            songID.setArtist(addArtist);
            songID.setGenre(addGenre);
            songID.setLength(addDuration);

            cout << "Song ID: " << songID.getSongId() << "\t || Song Title: " << songID.getTitle() << "\t || Song Artist: " << songID.getArtist() << "\t || Song Genre: " << songID.getGenre() << "\t || Song Duration: " << songID.getLength() << endl;

            success = list1.add(Song(songID.getSongId(), songID.getTitle(), songID.getArtist(), songID.getGenre(), songID.getLength()));

            if (success == true)
            {
                cout << "\nThe song '" << addSong << "' and attributes were added.\n";
            }
            else
            {
                cout << "\nThe song '" << addSong << "' and attributes were not added. There is already a similarly named song ID / song name and artist in the list.\n";
            }
        }

        // Name: Ezra Ho Jincheng.
        // Function: prints the list of songs saved in the linked list data structure.
        // Input Parameters: none.
        // Output Parameters: none.
        else if (a == 2)
        {
            cout << "\n == Display All Songs == \n";
            list1.printList();
        }

        // Name: Ezra Ho Jincheng.
        // Function: allows the user to remove the song just by using the song ID keyed in by the user.
        // Input Parameters: addSID.
        // Output Parameters: none.
        // user still can input decimal points.
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
            success = list1.remove(addSID);
        }


        else if (a == 4)
        {
            /*
            cout << "Option 4 Display Individual Song in more detail. \n";
            cout << "User add more information such as album details or reasons why they listened to this song. \n\n";
            cout << "Please enter ID of song to be shown in more detail: ";
            while (!(cin >> addSID) || addSID <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song ID integer: ";
            }

            success = list1.get(addSID);
            */
        }

       
        else if (a == 5)
        {

        cout << "You have selected:\nOption 5: Enqueue\n\nPlease enter Song ID of Song to be added to queue";
       

            while (!(cin >> addSID) || addSID <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song ID integer: ";
            }

            //success = queue1.enqueue(addSID);
            //success = queue1.enqueue(Song(songID.getSongId(), songID.getTitle(), songID.getArtist(), songID.getGenre(), songID.getLength()));
        }
        

        
        else if (a == 6)
        {
            cout << "You have selected:\nOption 6: Dequeue\n\nPlease enter Song ID of Song to be removed from queue";

            while (!(cin >> addSID) || addSID <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song ID integer: ";
            }

            //success = queue1.dequeue(addSID);
            //success = queue1.dequeue(Song(songID.getSongId(), songID.getTitle(), songID.getArtist(), songID.getGenre(), songID.getLength()));
        }

        else if (a == 0)
        {
            cout << "Exiting...\n\n";
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
    cout << "4\tDisplay individual song in more detail\n";
    cout << "5\tAdd songs to playlist queue\n";
    cout << "6\tRemove songs to playlist queue\n";
    cout << "0\tQuit\n";
}

