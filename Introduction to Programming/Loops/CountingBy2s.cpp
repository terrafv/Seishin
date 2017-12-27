//This program counts by 2 up to the number specified by the user.
//If the number is even, it is included in the count. If it is odd, it is not.

#include <iostream>
using namespace std;

int main()
{
    int counter = 0;
    int upperBound = 0;

    cout << "Enter a number to count to:\n";
    cin >> upperBound;

    while (counter <= upperBound)
    {
        cout << counter << endl;
        counter += 2;
    }

    return 0;
}
