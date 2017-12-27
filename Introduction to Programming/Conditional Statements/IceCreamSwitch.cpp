//This program asks the user to select a flavor of ice cream by entering a number 1-3.
//Depending on the selection, the program uses a switch statement to print an appropriate message.
//If any number outside the range 1-3 is selected, the program prints an error message.

#include <iostream>
using namespace std;

int main()
{
	int response = 0;

	cout << "Choose from the following flavors of ice cream:\n";
	cout << "1 - Vanilla, 2 - Chocolate, or 3 - Strawberry\n";
	cin >> response;

	switch(response)
	{
		case 1:
			cout << "You chose vanilla\n";
			break;

		case 2:
			cout << "You chose chocolate\n";
			break;

		case 3:
			cout << "You chose strawberry\n";
			break;

		default:
			cout << "Invalid selection\n";
			break;
	}

	return 0;
}
