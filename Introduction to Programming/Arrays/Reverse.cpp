//This program stores an arbitrary word in a char array and prints its reversal

#include <iostream>
using namespace std;

int main()
{
    char word[] = "Programming";

    int length = sizeof(word);

    for (int counter = length-2; counter >= 0; counter--)
        cout << word[counter];

    cout << endl;

    return 0;
}
