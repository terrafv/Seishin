#include <iostream>
using namespace std;

//Prints out the board
void printBoard(char board[3][3])
{
    cout << "   0 1 2\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i << "  ";
        for (int j = 0; j < 3; j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

//Returns true if the move is legal, false otherwise
bool isLegal(char board[3][3], int row, int col)
{
    if (row < 0 || row > 2 || col < 0 || col > 2)
    {
        cout << "Error: You cannot move off the board.\n";
        return false;
    }

    if (board[row][col] != '_')
    {
        cout << "Error: That space is already occupied.\n";
        return false;
    }

    return true;
}

//Returns true if the game is over, false otherwise
bool gameOver(char board[3][3])
{
    //Check the rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_')
            return true;

    //Check the columns
    for (int j = 0; j < 3; j++)
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != '_')
            return true;

    //Check the diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_') return true;

    //If we didn't find 3 in a row, return false
    return false;
}

int main()
{
    cout << "Welcome to TicTacToe!\n";

    //Create the board and fill it with spaces
    char board[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = '_';

    string player = "2 (O)";
    int row = -1, col = -1;

    //While the game is not over
    do {
        //Print the board
        printBoard(board);

        //Oscillate the prompt between players
        if (player[0] == '1')
            player = "2 (O)";
        else
            player = "1 (X)";

        //Get row and column
        do{
            cout << "Player " << player << ", enter a row number:\n";
            cin >> row;
            cout << "Player " << player << ", enter a column number:\n";
            cin >> col;
        } while (!isLegal(board, row, col));

        //Make the move (select X or O from prompt string)
        board[row][col] = player[3];

        //Clear the screen so things stay looking nice
        system("CLS");

    } while (!gameOver(board));

    cout << "Game over! Player " << player[0] << " wins!\n";
    printBoard(board);

    return 0;
}
