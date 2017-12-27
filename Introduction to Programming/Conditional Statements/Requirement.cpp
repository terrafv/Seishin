//This program asks the user what kind of student they are.
//Engineering students must take PF1.
//CSCE students must take PF1 and PF2.

#include <iostream>
using namespace std;

int main()
{
	string response = "";

	cout << "Are you an engineering student (y/n)?\n";
	cin >> response;

	if (response == "y")
	{
		cout << "Are you a CSCE student (y/n)?\n";
		cin >> response;

		if (response == "y")
			cout << "You must take PF1 and PF2.\n";
		else
			cout << "You must take PF1, but not PF2.\n";
	}
	else
		cout << "You don't have to take PF1 or PF2.\n";

	return 0;
}
