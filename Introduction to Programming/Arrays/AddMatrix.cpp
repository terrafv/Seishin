//This program randomly creates two matrices of size NxN and adds them.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    //Seed RNG and pick a random value for N
	srand(time(0));
	int n = rand() % 10 + 1;

	//Create two NxN matrices
	int x[n][n];
	int y[n][n];

	//Randomly fill matrices with numbers in [0,99]
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			x[r][c] = rand() % 100;
			y[r][c] = rand() % 100;
		}
	}

	//Print X
	cout << "Matrix x:\n";
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << setw(4) << x[r][c] << " ";
		}
		cout << endl;
	}

    //Print Y
	cout << "\nMatrix y:\n";
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << setw(4) << y[r][c] << " ";
		}
		cout << endl;
	}

	//Create Z
	int z[n][n];

	//Compute X + Y = Z
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			z[r][c] = x[r][c] + y[r][c];
		}
	}

    //Print Z
	cout << "\nMatrix z:\n";
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			cout << setw(4) << z[r][c] << " ";
		}
		cout << endl;
	}

	return 0;
}
