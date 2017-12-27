#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int SIZE = 10;
    int * numbers = new int[SIZE];

    for (int counter = 0; counter < SIZE; counter++)
        numbers[counter] = rand() % 20;

    for (int counter = 0; counter < SIZE; counter++)
        cout << numbers[counter] << " ";
    cout << endl;

    delete [] numbers;

    //nullptr is not defined in C++98.
    //If this program doesn't compile, try adjusting your compiler settings to work with C++11
    numbers = nullptr;

    return 0;
}
