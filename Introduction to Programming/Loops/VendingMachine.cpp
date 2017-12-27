#include <iostream>
using namespace std;

int main()
{
    int response = 0;
    cout << "Welcome!\n";

    do
    {
        cout << "\nPlease choose one of the following selections:\n";
        cout << "1 - Coke\n";
        cout << "2 - Pepsi\n";
        cout << "3 - Fanta\n";
        cout << "4 - Quit\n";
        cin >> response;

        if (response == 1)
            cout << "Dispensed 1 Coke!\n";

        else if (response == 2)
            cout << "Dispensed 1 Pepsi!\n";

        else if (response == 3)
            cout << "Dispensed 1 Fanta!\n";

        else if (response == 4)
            cout << "Goodbye!\n";

        else
            cout << "Error. Invalid entry.\n";

    } while (response != 4);

    return 0;
}
