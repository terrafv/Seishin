//This program simulates a vending machine.
//It asks the user to select a drink, deposit some money, and then computes the
//change in dollars, quarters, nickels and dimes.

//Note: This program doesn't always work perfectly. This is due to the fact that
//some floating point numbers (such as 0.1) cannot be represented precisely in binary.
//This can cause some of the calculations to be off by one cent. We can avoid this by converting
//everything to pennies and working only with integers. This will let us avoid the precision loss that
//sometimes accompanies floating point values.

//For more information, see this link:
//http://floating-point-gui.de/

#include <iostream>
using namespace std;

int main()
{
	int option = 0;
	float cost = 0;
	float change = 0;
	int change_in_pennies = 0;
	float deposit = 0;

    //Print user options
	cout << "Please choose an option: " << endl;
	cout << "1. Dr Pepper ($0.75)\n";
	cout << "2. Orange Fanta ($1.25)\n";
	cout << "3. Coke ($2.32)\n";
	cin >> option;

    //Check user input
	if(option == 1)
		cost = 0.75;
	else if(option == 2)
		cost = 1.25;
	else if (option == 3)
		cost = 2.32;
	else
	{
		cout << "Invalid input. Program terminated." << endl;
		return 0;
	}

	//Ask for deposit
	cout << "The price is $" << cost << endl;
	cout << "How much money are you depositing?" << endl;
	cin >> deposit;

    //Compute the change
	change = deposit - cost;

	//If the user does not enter enough money, the program quits
	if(change < 0)
	{
		cout << "Not enough money. Program terminated." << endl;
		return 0;
	}

    //Multiply the change by 100 to compute the change in pennies
	change_in_pennies = change*100;

	//Divide out each unit of currency and store the remainder
	cout << "Your change is\n";
	cout << change_in_pennies/100 << " dollar(s),\n";
	change_in_pennies = change_in_pennies%100;
	cout << change_in_pennies/25 << " quarter(s),\n";
	change_in_pennies = change_in_pennies%25;
	cout << change_in_pennies/10 << " dime(s),\n";
	change_in_pennies = change_in_pennies%10;
	cout << change_in_pennies/5 << " nickel(s),\n";
	change_in_pennies = change_in_pennies%5;
	cout << change_in_pennies << " pennies,\nfor a total of $" << change << ".\n";

	return 0;
}
