// Main file
// Program execution begins and ends here

#include <iostream>
#include <string>
#include "Songs.h"
#include "Playlist.h"
using namespace std;

void callMenu();

int main()
{
    callMenu();

    bool x = true;
    while (x == true)
    {
        int a;
        cout << "\nPlease choose a number: ";
        cin >> a;

        if (a == 1)
        {
            cout << "\n == Add Songs == \n";

        }

        else if (a == 2)
        {
            cout << "\n == Display Songs == \n";

        }

        else if (a == 3)
        {
            cout << "\n == Remove Songs == \n";

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
    cout << "\n\nChoice\tAction\n";
    cout << "------\t------\n";
    cout << "1\tAdd song\n";
    cout << "2\tDisplay songs\n";
    cout << "3\tRemove songs\n";
    cout << "4\tAdd songs to playlist queue\n";
    cout << "5\tRemove songs to playlist queue\n";
    cout << "0\tQuit\n";
}