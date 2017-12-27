//This program computes a running product of a series of numbers entered by the user.

#include <iostream>
using namespace std;

int main()
{
	int response = 0, accumulator = 0;

	cout << "Enter a series of integers to multiply (enter -1 to stop):\n";
	cin >> response;

	while (response != -1)
    {
        accumulator *= response;
        cout << "Enter another number:\n";
		cin >> response;
    }

	cout << "The product is " << accumulator << endl;

	return 0;
}
