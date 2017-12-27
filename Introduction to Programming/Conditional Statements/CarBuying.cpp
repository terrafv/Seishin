//This program asks the user if they want to buy a car.
//If they do, it asks them for a down payment.
//If they do not, the program quits.
//At the end, line 31 causes a compilation error because downPayment is out of scope.

#include <iostream>
using namespace std;

int main()
{
	string response = "";

	cout << "Are you buying a car?\n";
	cin >> response;

	if (response == "y")
	{
		float downPayment = 0;
		cout << "How much money are you putting down?\n";
		cin >> downPayment;

		if (downPayment >= 1000)
			cout << "Thank you!\n";
		else
			cout << "That's not enough money.\n";
	}
	else
		cout << "Goodbye.";

	cout << response << endl;
	cout << downPayment << endl; //Out of scope!

	return 0;
}
