#include <iostream>
using namespace std;

int main()
{
    int number = 0;

    cout << "Enter a positive odd number:\n";
    cin >> number;

    if (number > 0)
    {
        if (number % 2 == 2)
        {
            number--;
        }
        else
        {
            ; //Do nothing
        }
    }
    else
        ; //Do nothing

    cout << "Your new number is " << number << endl;

    return 0;
}
