#include <iostream>
using namespace std;

int main()
{
    //Initialize a variable
    int listSize = 0;

    //Get the list size
    cout << "How many numbers will you enter?\n";
    cin >> listSize;

    //Input validation
    while (listSize < 1 || listSize > 10)
    {
        cout << "Error: Please enter a number between 1 and 10\n";
        cin >> listSize;
    }

    //Declare more variables
    int counter = 0, entry, max, min;

    //Get the list of numbers
    while (counter < listSize)
    {
        cout << "Enter number " << counter + 1 << endl;
        cin >> entry;

        //Update max and min
        if(entry > max || counter == 0)
            max = entry;

        if (entry < min || counter == 0)
            min = entry;

        //Update counter
        counter++;
    }

    cout << "The maximum number entered was " << max << endl;
    cout << "The minimum number entered was " << min << endl;

    return 0;
}
