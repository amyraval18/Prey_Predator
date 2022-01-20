/* Amy Raval CSM135 
Predator Vs. Prey Project 
Goal: Include Bomb bug that explodes when pressing a character on the keyboard.
There should be a 5 second count down before the bomb bug explodes, 
and kills all organisms around the bomb bug. 
that's my project!!!!!
*/











#include <iostream>
#include <ctime>    // for time
#include "World.h"
#include <Windows.h>
#include <conio.h> // for kbhit 
#include <iomanip>
using namespace std;

void gotoxy(int x, int y) {
    if (x >= 0 && y >= 0) {
        COORD kursor;
        kursor.X = x;
        kursor.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), kursor);
    }
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // for color in display 
   
    World myWorld(time(0));

    myWorld.display();
   
    char ch{}; // intializing ch

    while (1)
    { 
        system("cls"); // clears each world 
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'b' || ch == 'B')
            {
                // add bug if user hits b 
                myWorld.createOrganisms(BUG, 1);
            }
            else if (ch == 'a' || ch == 'A')
            {
                // add ant if user hits a 
                myWorld.createOrganisms(ANT, 1);
            }
            else if (ch == 'z' || ch == 'Z')
            {
                // add bomb bug if user hits z 
                myWorld.createOrganisms(BOMB, 1); 
            }


        }
        SetConsoleTextAttribute(hConsole, 10);
        cout << "PREDATOR VS. PREY:: Amy Raval :) CSM135";// displaying my name

        myWorld.simulateOneStep();
        SetConsoleTextAttribute(hConsole, 11);
        myWorld.display();

        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n HOW TO PLAY:      ";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\n Press the letter B/b to add a BUG"; 
        SetConsoleTextAttribute(hConsole, 12);
        cout << "\n Press the letter A/a to add an ANT";
        SetConsoleTextAttribute(hConsole, 15);
        cout << "\n Press the letter Z/z to add a BOMB BUG!!!"; 

        Sleep(1000);
    }

    return 0;
}
