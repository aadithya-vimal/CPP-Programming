#include <iostream>
using namespace std;

int hits = 0, crow, ccol, remaining = 6, turns = 0, row, col, permiss, miss = 0, j = 1;

int main() {
    bool ships[4][4] = {
        {1,0,0,1},
        {0,0,1,0},
        {1,0,0,0},
        {0,0,1,1}
    };

    cout << "Welcome to Battleship in C++!\n";
    cout << "Enter the number of permitted misses:-\n";
    cin >> permiss;
    cout << "There are four rows and four columns in the board. There are six ships to hit.\nEnter your choice:-\n";

    while (hits <= 6 && turns <= (6 + permiss) && j == 1) {
        cout << "Enter row number:-\n";
        cin >> crow;
        cout << "Enter column number:-\n";
        cin >> ccol;

        row = crow - 1;//Appending correct values instead of index values for rows and cols
        col = ccol - 1;

        if (crow >= 1 && crow <= 4 && ccol >= 1 && ccol <= 4) {
            if (miss <= permiss) {
                turns++;  //Increment turns count for every turn attempted

                if (ships[row][col] == 1) {
                    cout << "HIT!\n";
                    remaining--;
                    hits++;
                    cout << "There are " << remaining << " ships left.\n\n";
                    ships[row][col] = 0;
                } else {
                    cout << "MISS!\n";
                    cout << "There are " << remaining << " ships left.\n\n";
                    miss = miss + 1;

                    if (miss > permiss) {
                        j = 0;
                        cout << "You have no more misses allowed.\n";
                        cout << "You have hit " << hits << " ships in " << turns << " turns.\n";
                    }
                }
            }
        } else {
            cout << "Enter a row and column between 1 and 4.\n";
        }
    }

    cout << "\n--- GAME OVER ---\n";

    if (j == 0) {
        // Message already displayed above
        cout << "Game over due to exceeding permitted misses!\n";
    } else if (hits == 6) {
        cout << "You have sunken all six ships in " << turns << " turns.\n";
    } else if (turns > (6 + permiss)) {
        cout << "You have no more turns.\n" << "You have hit " << hits << " ships in " << turns << " turns.\n";
    }
    cout << "Press Enter to exit...";
    cin.ignore();  // Clear any remaining input
    cin.get();     // Wait for user to press Enter

    return 0;
}
