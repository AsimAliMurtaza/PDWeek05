#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void maze();
void gotoxy(int x, int y);
void erase(int x, int y);
void pacMove(int x, int y) ;
char getCharAtxy (short int x, short int y);
void printScore(int score);


main()
{

    int x = 5;
    int y = 3;
    int score = 0;
    bool gameRunning = true;

    system("cls");
    maze();
    pacMove(x, y);

    while(gameRunning)
    {
        if(GetAsyncKeyState(VK_LEFT))
        {
            char nextLocation = getCharAtxy(x-1, y);
            if (nextLocation == ' ')
            {
                erase(x, y);
                x = x - 1;
                pacMove(x, y);
            }
            if (nextLocation == '.')
            {
                erase(x, y);
                x = x - 1;
                pacMove(x, y);
                score = score + 1;
            }
        }
        if(GetAsyncKeyState(VK_RIGHT))
        {
            char nextLocation = getCharAtxy(x+1, y);
            if (nextLocation == ' ')
            {
                erase(x, y);
                x = x + 1;
                pacMove(x, y);
            }
            if (nextLocation == '.')
            {
                erase(x, y);
                x = x + 1;
                pacMove(x, y);
                score = score + 1;
            }
        }
        if(GetAsyncKeyState(VK_UP))
        {
            char nextLocation = getCharAtxy(x, y-1);
            if (nextLocation == ' ')
            {
                erase(x, y);
                y = y - 1;
                pacMove(x, y);
            }
            if (nextLocation == '.')
            {
                erase(x, y);
                y = y - 1;
                pacMove(x, y);
                score = score + 1;
            }
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            char nextLocation = getCharAtxy(x, y+1);
            if (nextLocation == ' ')
            {
                erase(x, y);
                y = y + 1;
                pacMove(x, y);
            }
            if (nextLocation == '.')
            {
                erase(x, y);
                y = y + 1;
                pacMove(x, y);
                score = score + 1;
            }
        }
        
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            gameRunning = false;
        }
        printScore(score);
        Sleep(50);
    }
}







void printScore(int score)
{
    gotoxy(1, 28);
    cout << "Score: " << score;
}


void pacMove(int x, int y)
{
   gotoxy(x, y);
   cout << "P";
   Sleep(100);
}
void maze()
{
    cout << ("######################################################################################   ") << endl;
    cout << ("||.. .................................................................     .......  ||   ") << endl;
    cout << ("||..  %%%%%%%%%%%%%%                      %%%%%%%%%%%%%%%    |%|....        %%%%%   ||   ") << endl;
    cout << ("||..       |%|   |%|         |%|.....     |%|         |%|    |%|....         |%|    || ") << endl;
    cout << ("||..       |%|   |%|         |%|.....     |%|         |%|    |%|....         |%|    ||   ") << endl;
    cout << ("||..       |%|   |%|         |%|.....     %%%%%%%%%%%%%%%    |%|....        %%%%%.. ||   ") << endl;
    cout << ("||..       %%%%%%%%   .....  |%|.....      ...............                       .. ||   ") << endl;
    cout << ("||..       |%|        .....  |%|.....      %%%%%%%%%%%%      |%|....        %%%%%.. || ") << endl;
    cout << ("||..       %%%%%%%%%% .....                |%|.......        |%|....         |%|... || ") << endl;
    cout << ("||..               |%|.....                |%|.......|%|     |%|....         |%|... || ") << endl;
    cout << ("||..               |%|.....                   .......|%|                     |%|... || ") << endl;
    cout << ("||..     ......... |%|.....  |%|              .......|%|         ....|%|     |%|... || ") << endl;
    cout << ("||..|%|  |%|%%%|%|.         %%%%%%%%%%%%        %%%%%%%%         ....|%|....        || ") << endl;
    cout << ("||..|%|  |%|   |%|..             .....|%|                        ....|%|....        || ") << endl;
    cout << ("||..|%|  |%|   |%|..             .....|%|                        ....|%|....        || ") << endl;
    cout << ("||..|%|            .             .....|%|                    |%| ....|%|....        || ") << endl;
    cout << ("||..|%|  %%%%%%%%%%%%%                   %%%%%%%%%%%%%       |%| ....|%|%%%%%%%     || ") << endl;
    cout << ("||.......................................................    |%| ....               || ") << endl;
    cout << ("||..  ...................................................                           || ") << endl;
    cout << ("||..|%|  |%|   |%|..           %%%%%%%%%%%%%     ......|%|   |%| ....|%|...         || ") << endl;
    cout << ("||..|%|  |%|   |%|..                     |%|      %%%%%%%%   |%| ....|%|...         || ") << endl;
    cout << ("||..|%|  |%|   |%|......                 |%|                 |%| ....|%|...         || ") << endl;
    cout << ("||..|%|           ......                 |%|                 |%| ....|%|...         || ") << endl;
    cout << ("||..|%|                                  |%|                 |%| ....|%|...         || ") << endl;
    cout << ("||..|%|  %%%%%%%%%%%%%                      %%%%%%%%%%%%%%%  |%| ...............    || ") << endl;
    cout << ("||.........................................................  |%| ...............    || ") << endl;
    cout << ("||  .......................................................                         || ") << endl;
    cout << ("###################################################################################### ") << endl;
}
void erase(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void gotoxy (int x, int y)
{
    COORD coordinates;
    coordinates.X = x; 
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
}
char getCharAtxy(short int x,short int y)
{
CHAR_INFO ci;
COORD xy = {0 ,0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}