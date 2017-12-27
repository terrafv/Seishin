//This program checks if an arbitrary word is a palindrome
//The program is case sensitive, and does not account for punctuation or spaces

#include <iostream>
using namespace std;

int main()
{
    string word = "solos";

    for (int counter = 0; counter < word.size()/2; counter++)
    {
        if (word[counter] != word[word.size() - counter - 1])
        {
            cout << word << " is not a palindrome.\n";
            return 0;
        }
    }

    cout << word << " is a palindrome!\n";

    return 0;
}
