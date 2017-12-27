//This program examines a series of 9 numbers and checks if it's a magic square.
//A magic square is a 3x3 grid of the numbers 1-9 in which:
//	(1) the numbers 1-9 each appear once
//	(2) the sums of all rows, columns, and diagonals equals 15
//For example: 2 7 6 9 5 1 4 3 8

#include <iostream>
using namespace std;

int main()
{
	bool magic = true;
	int square[3][3];

	//Get the numbers for the square
	cout << "Enter 9 numbers:\n";
	for (int x = 0; x < 9; x++)
		cin >> square[x/3][x%3];

	//Print the square
	cout << "\nYou entered:\n";
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			cout << square[r][c] << " ";
		}
		cout << endl;
	}

	//Create an array to count the numbers, initialize elements to 0
	int count[9];
	for (int index = 0; index < 9; index++)
		count[index] = 0;

	//Scan the square and count the numbers
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			if (square[r][c] < 1 || square[r][c] > 9)
				magic = false;

			count[square[r][c] - 1]++;
		}
	}

	//Check the results of the counting step
	for (int index = 0; index < 9; index++)
	{
		if (count[index] != 1)
			magic = false;
	}

	//Check the sum of all the rows and columns
	int sum = 0;
	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 3; c++)
		{
			sum = sum + square[r][c];
		}

		if (sum != 15)
			magic = false;

		sum = 0;

	}

	//Check the sum of the forward diagonal
	if (square[0][0] + square[1][1] + square[2][2] != 15)
		magic = false;

	//Check the sum of the backward diagonal
	if (square[2][0] + square[1][1] + square[0][2] != 15)
		magic = false;

	//Print the final result
	if (magic)
		cout << "\nThis is a magic square.\n";
	else
		cout << "\nThis is not a magic square.\n";

	return 0;
}
