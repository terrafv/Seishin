#include <iostream>
using namespace std;

int main()
{
	int response = 0;

	cout << "Enter a series of integers (enter -1 to stop):\n";
	cin >> response;

	while (response != -1)
    {
        cout << "Enter another number:\n";
		cin >> response;
    }

	cout << "Goodbye!\n";

	return 0;
}
