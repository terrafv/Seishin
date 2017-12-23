/*
Author: Josh Burbridge
Date: 21 December 2017
This game simulates the classic 15-puzzle seen in toy stores and online.

Ideas for improvement:
    +Add support for arrow keys instead of WASD
    +Combine with a GUI instead of playing in the console
        If using a GUI, make a picture puzzle instead of a number puzzle
        Make it a video puzzle like in Banjo Tooie
    +Create an AI that solves this, and use it to provide hints to the player
*/

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

//Attempts to make a move. Returns true if successful, false if move is illegal
bool makeMove(int board[4][4], char move)
{
        /*  First, locate the space in the board. Seems kind of stupid to do this each time,
            but the alternative is keeping track of the space with global variables, or passing
            the coordinates to all different functions. This is a good example of a trade-off between
            efficiency and readable code. In this case, we would not notice the small performance
            boost, so it's better to choose readable code.
        */
        int spaceR = 0, spaceC = 0;
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                if(board[i][j] == 0)
                {
                    spaceR = i;
                    spaceC = j;
                }
            }
        }

        //If user wants to move up, make sure there is a tile to move up
        if(move == 'w' && spaceR != 3)
        {
            board[spaceR][spaceC] = board[spaceR+1][spaceC];
            board[spaceR+1][spaceC] = 0;
        }

        //Move left
        else if(move == 'a' && spaceC != 3)
        {
            board[spaceR][spaceC] = board[spaceR][spaceC+1];
            board[spaceR][spaceC+1] = 0;
        }

        //Move down
        else if(move == 's' && spaceR != 0)
        {
            board[spaceR][spaceC] = board[spaceR-1][spaceC];
            board[spaceR-1][spaceC] = 0;
        }

        //Move right
        else if(move == 'd' && spaceC != 0)
        {
            board[spaceR][spaceC] = board[spaceR][spaceC-1];
            board[spaceR][spaceC-1] = 0;
        }

        else
            return false;

        //Move was successful, so return true
        return true;
}

//Initialize the board by making random moves
//This guarantees that the board will not begin in any unsolvable configurations
void init(int board[4][4])
{
    //Fill the board from 0-15
    int number = 0;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            board[i][j] = number;
            number++;
        }
    }

    //Make 50 moves
    srand(time(NULL));
    char moves[4] = {'w','a','s','d'};
    for(int x = 0; x < 50; x++)
        makeMove(board, moves[rand()%4]);
}

//Returns true if the game is over, false if not
bool gameOver(int board[4][4])
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(board[i][j] != i*4+j)
                return false;

    return true;
}

//Print the board
void printBoard(int board[4][4])
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(board[i][j] == 0)
                cout << setw(3) << "_";
            else
                cout << setw(3) << board[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    cout << "Welcome to 15-puzzle!\n";

    //Create and initialize board
    int board[4][4];
    init(board);

    //Set up some variables
    bool win = false;
    char move = ' ';

    //While user hasn't won
    while(!win)
    {
        //Clear screen and print board
        system("CLS");
        printBoard(board);

        //Get user's move
        cout << "Enter a move (WASD), or x to quit:\n";
        cin >> move;

        //If user wants to quit, leave the loop
        if(move == 'x')
            break;

        //While we can't make the move, keep asking
        while(!makeMove(board, move))
        {
            system("CLS");
            printBoard(board);

            cout << "Error: Invalid move.\n";
            cout << "Enter a move (WASD), or x to quit:\n";
            cin >> move;
        }

        //Check if game is over
        win = gameOver(board);
    }

    //Clear the screen and print ending message
    system("CLS");
    printBoard(board);

    if(win)
        cout << "Congratulations! You win!\n";
    else
        cout << "Better luck next time.\n";

    return 0;
}
