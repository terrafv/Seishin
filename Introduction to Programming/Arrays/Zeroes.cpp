//This program reads an array of numbers and shifts all the 0s to the back of the array
//All the non-zero values will appear at the front of the array

#include <iostream>
using namespace std;

int main()
{
    const int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE] = {1, 0, 0, 5, 12, 0, 8, 7, 6, 0};

    cout << "Numbers before moving zeroes\n";
    for (int counter = 0; counter < ARRAY_SIZE; counter++)
        cout << numbers[counter] << " ";
    cout << endl;

    int endPointer = ARRAY_SIZE - 1;
    int temp = 0;

    //Scan the array to find numbers to swap
    for (int counter = 0; counter < endPointer; counter++)
    {
        //while endpointer points to a 0, advance it
        while (numbers[endPointer] == 0 && endPointer > counter)
            endPointer--;

        //If the counter points to a 0, swap it with an element in the back
        if (numbers[counter] == 0)
        {
            temp = numbers[counter];
            numbers[counter] = numbers[endPointer];
            numbers[endPointer] = temp;
        }
    }

    cout << "Numbers after moving zeroes\n";
    for (int counter = 0; counter < ARRAY_SIZE; counter++)
        cout << numbers[counter] << " ";
    cout << endl;

    return 0;
}
