#include <iostream>
#include <cmath>
using namespace std;

int factorial(const int number)
{
    if (number > 12)
    {
        cout << "Error (factorial): Number is too large to compute factorial.\n";
        cout << "Currently, this function uses 32-bit ints and can only compute up to 12!\n";
        return -1;
    }
    else if (number < 0)
    {
        cout << "Error (factorial): Cannot compute factorial of a negative number.\n";
        return -1;
    }
    else if (number == 0)
        return 1;
    else
        return number * factorial(number-1);
}

int trialDivision(const int number)
{
    for(int i=2; i < sqrt(number); i++)
    {
        if(number % i == 0)
            return 0;
    }
    return 1;
}

int wilsonsTheorem(const int number)
{
    int fact = factorial(number-1);

    if (fact == -1)
    {
        cout << "Error (wilsonsTheorem): Factorial function contained an error.\n";
        return -1;
    }
    else if(fact % number == number - 1)
        return 1;
    else
        return 0;
}

int main()
{
    int number = 0;
    int num_tests = 2;

    //Get user input
    do{
        cout << "Enter a number in the range [2,INT_MAX):\n";
        cin >> number;
    } while(number < 2);
    cout << "\n";

    //Create an array for test names
    string test_names[num_tests];
    test_names[0] = "Trial Division";
    test_names[1] = "Wilson's Theorem";

    //Create an array for test results
    int test_results[num_tests];
    test_results[0] = trialDivision(number);
    test_results[1] = wilsonsTheorem(number);

    //Print test results
    cout << "\nResults:\n";
    for (int i = 0; i < num_tests; i++)
    {
        cout << test_names[i] << ": ";

        if(test_results[i] == 1)
            cout << number << " is prime.\n";
        else if (test_results[i] == 0)
            cout << number << " is prime\n";
        else
            cout << "Error.";
    }
    cout << "\n";

    return 0;
}
