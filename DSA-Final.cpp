// This file contains 'main' functions.
// Program execution begins and ends here.

#include <iostream>
#include <string>
#include "Song.h"
#include "Playlist.h"
#include "LinkedList.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main()
{
    bool success = false;
    string addSong, addArtist, addGenre, addDescription, addAlbum;
    int addSID, addDuration;
    void callMenu();
    int i = 1;


    // linked list that contains the songs.
    LinkedList list1;

    // queue containing the song objects
    Queue queue1;

    Song songID;
    // do running number for song ID

    Stack s;

    // infinite loop until exit.
    bool x = true;
    while (x == true)
    {
        callMenu();
        int a;
        cout << "\nPlease choose a choice: ";

        while (!(cin >> a) || a < 0) // validation to ensure only numbers
        {
            cout << "\nInvalid choice, please enter a valid choice: ";
            cin.clear();
            while (cin.get() != '\n'); // empty loop
        } // works

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

            cout << "\nPlease enter the song album: ";
            getline(cin, addAlbum);
            while (addAlbum.empty())
            {
                cout << "\nInvalid input. Please enter the song album: ";
                cin.clear();
                getline(cin, addAlbum);
            }

            cout << "\nPlease enter the song description: ";
            getline(cin, addDescription);
            while (addDescription.empty())
            {
                cout << "\nInvalid input. Please enter the song description: ";
                cin.clear();
                getline(cin, addDescription);
            }

            // users can still add decimal numbers
            cout << "\nPlease enter the song duration: ";
            while (!(cin >> addDuration) || addDuration <= 0)
            {
                cout << "\nPlease enter a valid song duration integer: ";
                cin.clear();
                while (cin.get() != '\n'); // empty loop
            }

            songID.setSongId(i);
            i++;
            songID.setTitle(addSong);
            songID.setArtist(addArtist);
            songID.setGenre(addGenre);
            songID.setLength(addDuration);
            songID.setAlbum(addAlbum);
            songID.setDescription(addDescription);

            success = list1.add(Song(songID.getSongId(), songID.getTitle(), songID.getArtist(), songID.getGenre(), songID.getLength(), songID.getAlbum(), songID.getDescription()));

            queue1.enqueue(Song(songID.getSongId(), songID.getTitle(), songID.getArtist(), songID.getGenre(), songID.getLength(), songID.getAlbum(), songID.getDescription()));

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

        // Name: Ezra Ho Jincheng.
        // Function: allows the user to obtain more details of the song just by using the song ID keyed in by the user.
        // Input Parameters: addSID.
        // Output Parameters: song ID, song name, song artist, song genre, song duration, song album, song description.
        // user still can input decimal points.
        else if (a == 4)
        {
            cout << "\n == Obtain Song == \n";
            cout << "Please enter ID of song to be obtained: ";
            while (!(cin >> addSID) || addSID <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song ID integer: ";
            }
            s.push(list1.get(addSID));
        }

        else if (a == 5)
        {
            cout << "You have selected:\nOption 5: Enqueue\n\nPlease enter Song ID of Song to be added to queue: ";
       
            while (!(cin >> addSID) || addSID <= 0)
            {
                cin.clear();
                while (cin.get() != '\n')
                {
                    continue;
                }
                cout << "\nPlease enter a valid song ID integer: ";
            }
            success = queue1.enqueue(Song(songID.getSongId(), songID.getTitle(), songID.getArtist(), songID.getGenre(), songID.getLength(), songID.getAlbum(), songID.getDescription()));

            if (success == true)
            {
                cout << "Song ID '" << songID.getSongId() << "' has been enqueued.\n";
                cout << "\nEnqueue List:\n";
            }
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

        // Name: Hannah Leong Jia Wen
       // Function: Allows use to view Search History (from option 4) and allows them to delete previous searches
       // Input Parameters: search, n.
       // Output Parameters: song ID, song name, song artist, song genre, song duration, song album, song description.
        else if (a == 7)
        {
        cout << "\n == Search History == \n";
        s.displayInOrder();
        if (!s.isEmpty())
        {
            string search;
            int n;
            cout << "\n1\tDelete Search History";
            cout << "\n2\tGo Back to Menu";
            cout << "\nPlease Enter A number: ";
            cin >> n;
            if (n == 1)
            {
                cout << "\nDelete latest or entire search history?(L/E): ";
                cin >> search;
                if (search == "L" || search == "l")
                {
                    s.displayInOrder();
                }
                else
                {
                    s.~Stack();
                    cout << "Search History Deleted";
                }
            }
            else
            {
                continue;
            }
        }
        else
        {
            continue;
        }
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
    cout << "4\tObtain song information\n";
    cout << "5\tAdd songs to playlist queue\n";
    cout << "6\tRemove songs from playlist queue\n";
    cout << "7\tSearch History\n";
    cout << "0\tQuit\n";
}