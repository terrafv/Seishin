//This program implements Hangman, a popular letter-guessing game.
//NOTE: For simplicity,
//  (1) this program only works with lowercase letters
//  (2) it doesn't detect impossible scenarios such as only having 2 guesses for a 10 letter word

#include <iostream>
using namespace std;

int main()
{
    int numGuesses = 0;
    string board = "";
    string answer = "";
    bool letters[26];
    char guess = ' ';

    //Set all our booleans to false
    for (int x = 0; x < 26; x++)
        letters[x] = false;

    //Get information from player 1
    cout << "Player 1, please enter your secret word:\n";
    cin >> answer;

    cout << "How many guesses should player 2 have?\n";
    cin >> numGuesses;

    //Populate the board with blanks
    for (int x = 0; x < answer.size(); x++)
        board += "_";

    //This loop processes each guess
    for (int x = 0; x < numGuesses; x++)
    {
        cout << board << endl;

        //Get player 2's guess
        cout << "Player 2, enter guess of " << x+1 << " of " << numGuesses << ":\n";
        cin >> guess;

        //Make sure they haven't guessed this letter before
        while (letters[guess - 97] == true)
        {
            cout << "You have already guessed this letter! Try again:\n";
            cin >> guess;
        }

        //Record the fact that they've guessed this letter
        letters[guess - 97] = true;

        //Check the answer for any occurrences of their guess
        for (int y = 0; y < answer.size(); y++)
            if (answer[y] == guess)
                board[y] = guess;

        //Check if they've solved the puzzle
        for (int y = 0; y < answer.size(); y++)
        {
            //If we find one mismatch, they haven't solved the puzzle
            if (board[y] != answer[y])
                break;

            //If we've reached the final iteration, there are no mismatches, so they've won
            if (y == answer.size() - 1)
            {
                cout << board << endl;
                cout << "Congratulations, you win!\n";
                return 0;
            }
        }
    }

    //If we've reached this point, we know they've used all their guesses without winning
    cout << "Sorry, you lost!\n";

    return 0;
}
