#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int linearSearch(int numbers[], int SIZE, int entry)
{
    for (int i = 0; i < SIZE; i++)
    {
        if (numbers[i] == entry)
            return i;
    }

    return -1;
}

int binarySearch(int numbers[], int SIZE, int entry)
{
    int left = 0;
    int right = SIZE - 1;
    int middle;

    while(left <= right)
    {
        middle = (left + right) / 2;

        if (numbers[middle] == entry)
            return middle;

        else if (numbers[middle] > entry)
            right = middle - 1;

        else
            left = middle + 1;
    }

    return -1;
}

int rbs(int numbers[], int left, int right, int entry)
{
    if (left > right)
        return -1;

    int middle = (left + right) / 2;

    if (numbers[middle] == entry)
        return middle;

    else if (numbers[middle] > entry)
        return rbs(numbers, left, middle - 1, entry);

    else
        return rbs(numbers, middle + 1, right, entry);

}

void print(int numbers[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << setw(5) << numbers[i];
        if (i % 10 == 9)
            cout << endl;
    }
}

int main()
{
    srand(time(0));

    int SIZE = 100;
    int * numbers = new int[SIZE];

    for (int i = 0; i < SIZE; i++)
        numbers[i] = rand() % SIZE;

    sort(numbers, numbers + SIZE);
    print(numbers, SIZE);

    int entry = -1;
    cout << "What number would you like to search for?\n";
    cin >> entry;

    cout << "Iterative Binary search: ";
    int result = binarySearch(numbers, SIZE, entry);
    if (result != -1)
        cout << entry << " was found at location " << result << endl;
    else
        cout << entry << " was not found.\n";


    cout << "Recursive Binary search: ";
    result = rbs(numbers, 0, SIZE - 1, entry);
    if (result != -1)
        cout << entry << " was found at location " << result << endl;
    else
        cout << entry << " was not found.\n";

    cout << "Linear search: ";
    result = linearSearch(numbers, SIZE, entry);
    if (result != -1)
        cout << entry << " was found at location " << result << endl;
    else
        cout << entry << " was not found.\n";

    delete [] numbers;
    numbers = nullptr;

    return 0;
}
