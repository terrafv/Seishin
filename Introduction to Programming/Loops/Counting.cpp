#include <iostream>
using namespace std;

int main()
{
	int counter = 0;
	int upperBound = 0;

	cout << "How many times should the loop run?\n";
	cin >> upperBound;

	while (counter < upperBound)
	{
		cout << "This is iteration " << counter
			 << " of " << upperBound << endl;
		counter++;
	}

	return 0;
}
