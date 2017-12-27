#include <iostream>
using namespace std;

int main()
{
    bool foundCombo = false;
	int digit1 = 5, digit2 = 1;

	for (int guess1 = 0; guess1 < 10; guess1++)
	{
	    if (guess1 == 1 || guess1 == 3)
            continue;

		for (int guess2 = 0; guess2 < 10; guess2++)
		{
            cout << "guess 1: " << guess1 << "   ";
		    cout << "guess 2: " << guess2 << endl;
			if (guess1 == digit1 && guess2 == digit2)
			{
				cout << "You broke the combination! The answer is "
					 << digit1 << digit2 << endl;
			}
		}
	}
}
