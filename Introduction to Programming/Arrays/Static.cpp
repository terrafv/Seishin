#include <iostream>
using namespace std;

int main()
{
    int size = 1;

    cout << "Enter a size for the array\n";
    cin >> size;

    int numbers[size];
    int entry;

    for (int counter = 0; counter < size; counter++)
    {
        cout << "Enter number " << counter + 1 << ":\n";
        cin >> numbers[counter];
    }

    //This is a range-based for loop. This will not work in C++98.
    //If this program doesn't compile, try adjusting your compiler settings to work with C++11
    for (int num : numbers)
        cout << num << " ";

    cout << endl;

    cout << sizeof(numbers) << endl;

    return 0;
}
