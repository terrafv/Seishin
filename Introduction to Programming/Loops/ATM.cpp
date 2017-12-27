//This program simulates an ATM. It presents the user with a menu system
//and takes an appropriate action based on their selection.

//Extra practice: Assume the user has two accounts, checking and savings.
//What changes would you need to make to this code to make the program work
//with both accounts? Hint: the conditional operator may prove useful here.

#include <iostream>
using namespace std;

int main()
{
    int menuResponse = 0;
    int accountResponse = 0;
    float account = 50.00;
    float amount = 0;

	do
	{
	    cout << "Enter one of the following menu options:\n";
	    cout << "1 - Balance Inquiry\n";
	    cout << "2 - Deposit\n";
	    cout << "3 - Withdrawal\n";
	    cout << "4 - Quit\n";
	    cin >> menuResponse;

	    if (menuResponse == 1)
            cout << "Your account balance is: " << account << endl;

        else if (menuResponse == 2)
        {
            cout << "How much would you like to deposit?\n";
            cin >> amount;

            while (amount < 0)
            {
                cout << "Please enter a positive number:\n";
                cin >> amount;
            }

            account += amount;
        }

        else if (menuResponse == 3)
        {
            cout << "How much would you like to withdraw?\n";
            cin >> amount;

            while (amount < 0 || account - amount < 0)
            {
                if (amount < 0)
                    cout << "Error. You entered a negative number.\n";
                else
                    cout << "Error. You cannot withdraw " << amount
                         << " when your account balance is only " << account << ".\n";
                cin >> amount;
            }

            account -= amount;
        }

        else if (menuResponse == 4)
            cout << "Goodbye!\n";

        else
            cout << "Invalid entry. Try again.\n";

	} while (menuResponse != 4);

	return 0;
}
