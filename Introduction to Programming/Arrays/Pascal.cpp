//This program computes Pascal's triangle up to a certain number of rows

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int n = 0;

    //Ask how many rows
	cout << "How many rows (max 10)?\n";
	cin >> n;

	//Input validation
	while (n < 1 || n > 10)
	{
		cout << "Try again.\n";
		cin >> n;
	}

	//Create matrix and initialize first and last elements of each row to 1
	int pascal[n][n];
	for (int r = 0; r < n; r++)
	{
		pascal[r][0] = 1;
		pascal[r][r] = 1;
	}

	//Fill in the inner values using recursive equation
	for (int r = 2; r < n; r++)
	{
		for (int c = 1; c < r; c++)
		{
			pascal[r][c] = pascal[r-1][c-1] + pascal[r-1][c];
		}
	}

    //Print Pascal's triangle
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c <= r; c++)
		{
			cout << setw(3) << pascal[r][c] << " ";
		}
		cout << endl;
	}

	return 0;
}
