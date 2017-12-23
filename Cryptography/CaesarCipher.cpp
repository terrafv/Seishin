/*
    Author: Josh Burbridge
    Date: 22 December 2017
    Description: This program uses the classic Caesar cipher to encrypt and decrypt messages.
        It runs in a loop, so you can encrypt or decrypt as many times as you want. If you need
        to read from a file instead, it should be easy to modify (or just use input redirection).
        As always, the emphasis is on didactic programming, so this code is meant to be easy to read.

        The program is versatile in that the user can type in any number for the key, and it will
        be mapped to some integer in the range [0,25]. In C++, the modulo operator can return
        negative numbers, which can cause problems with the rotate() function, so this was a
        necessary change. Additionally, there is a brute force option which take a ciphertext and
        prints the remaining 25 rotations. Just choose whichever phrase looks like English.

        Because there are only 26 "unique" keys, Caesar ciphers are very easy to break. They are
        only suitabled for educational purposes. If you need actual security, use a stronger cipher.

    Ideas for improvement:
        +Add support for numbers, punctuation, and other characters.
*/

#include <iostream>
using namespace std;

//Take a string m and use the key to perform a rotation on each of the letters. Case is preserved,
//and any non-alphabetic characters are unchanged. This function shifts all letters to the right.
//In C++, -2 % 26 => -2, not 24. We can avoid dealing with negatives by always shifting right.
string rotate(string m, int key)
{
    string output = "";
    for (int i = 0; i < m.size(); i++)
    {
        if (m[i] >= 'A' && m[i] <= 'Z')
            output += char((m[i] - 'A' + key) % 26 + 'A');
        else if (m[i] >= 'a' && m[i] <= 'z')
            output += char((m[i] - 'a' + key) % 26 + 'a');
        else
            output += m[i];
    }
    return output;
}

int main()
{
    cout << "Welcome to the Caesar cipher program.\n";

    int option = 0;
    do{
        //Print menu
        cout << "Select an option:\n";
        cout << "1) Encrypt\n";
        cout << "2) Decrypt\n";
        cout << "3) Brute force\n";
        cout << "4) Quit\n";
        cin >> option;
        cin.ignore();

        //Make sure option is valid
        while (option < 1 || option > 4)
        {
            cout << "Error: Invalid selection. Try again.\n";
            cin >> option;
        }

        //If option == 4, quit
        if (option == 4)
            break;

        //Get the message
        cout << "Enter a string:\n";
        string message;
        getline(cin, message);

        //Get the key if necessary. Key can be any integer.
        int key = 0;
        if (option == 1 || option == 2)
        {
            cout << "Enter the key:\n";
            cin >> key;
        }

        //This maps any value into the range [0,25].
        //Try working a few examples on paper to understand how.
        key = (key % 26 + 26) % 26;

        //Encrypt a message
        if (option == 1)
            cout << rotate(message, key) << endl;

        //Decrypt a message. The rotate() function uses a rightward (forward) shift,
        //so we need to subtract key from 26 to find the amount to shift right.
        //Remember, shifting 5 letters to the left is the same as 21 letters to the right.
        else if (option == 2)
            cout << rotate(message, 26-key) << endl;

        //Brute force a ciphertext by printing all possible rotations (except 0)
        else if (option == 3)
            for (int i = 1; i < 26; i++)
                cout << rotate(message, i) << endl;

    } while (option != 4);

    cout << "Goodbye.\n";

    return 0;
}
