#include <iostream>
using namespace std;

int main()
{
    int number = 100;
    int * ptr = nullptr;

    ptr = &number;

    cout << "The value of number is " << number << endl;
    cout << "The address of number is " << &number << endl;
    cout << "The address that ptr points to is " << ptr << endl;

    *ptr = -1;

    cout << "The value of number is now " << number << endl;

	return 0;
}
