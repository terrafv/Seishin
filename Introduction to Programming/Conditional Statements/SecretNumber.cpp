//This program lets the user attempt to guess a secret number between 1 and 100.
//If they guess correctly, a congratulatory message is displayed.
//The program always says "Thanks for playing", whether they win or lose.

#include <iostream>
using namespace std;

int main()
{
	int secretNumber = 37;
	int guess = 0;

	cout << "Guess a number between 1 and 100\n";
	cin >> guess;

	if (guess == secretNumber)
	{
		cout << "Congratulations! You win!\n";
	}

	cout << "Thanks for playing.\n";

	return 0;
}
