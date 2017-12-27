//This program asks the user what kind of ice cream they want to buy.
//Depending on the selection, the program prints an appropriate message.

#include <iostream>
using namespace std;

int main()
{
	string response = "";

	cout << "Choose from the following flavors of ice cream:\n";
	cout << "Vanilla, Chocolate, or Strawberry\n";
	cin >> response;

	if (response == "Vanilla")
		cout << "You chose vanilla\n";
	else if (response == "Chocolate")
		cout << "You chose chocolate\n";
	else if (response == "Strawberry")
		cout << "You chose strawberry\n";
	else
		cout << "Your selection is invalid.\n";

	return 0;
}
