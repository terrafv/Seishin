#include <climits>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

//Compute factorial up to 12!
//Just adding this comment to test github. Remove at a later date.
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

//Uses Euclidean algorithm to compute greatest common divisor
//Returns int in range [1,min(a,b)] or -1 for failure
int gcd (int a, int b)
{
    if(a < 1 || b < 1)
    {
        cout << "Error (gcd): a and b must be at least 1\n";
        cout << "You entered a: " << a << ", b: " << b << endl;
        return -1;
    }

    int temp = 0;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int safePow(int a, int b)
{
    int total = 1;
    for (int i = 0; i < b; i++)
    {
        if (INT_MAX / a <= total)
        {
            cout << "Error (safePow): computing " << a << "^" << b << " will cause overflow.\n";
            return -1;
        }
        else
            total *= a;
    }
    return total;
}

//Determine if two ints are coprime.
//a and b are coprime iff gcd(a, b) = 1
bool coprime (int a, int b)
{
    if (gcd(a, b) == 1)
        return true;
    else
        return false;
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

//Uses Fermat's test to determine primality
//This is a probabilistic test, which means there is a small chance it could return an incorrect answer.
//      To diminish this chance, run the test many times.
//Returns 1 if prime, 0 if composite, -1 for error.
//NOTE: Fermat's test does not work on Carmichael numbers, of which there are infinitely many.
//      A Carmichael number is a composite number for which the test will always return 1, no matter
//      which value of a is chosen. For more reliable tests, try Miller-Rabin or Solovay Strassen.
//WARNING: This function can experience integer overflows very easily.
int fermatTest(int number, int num_tests)
{
        //Randomly pick a number a in the range [2, number-2]
        srand(time(NULL));
        int a = rand() % (number - 2) + 2;

        //If a^(n-1) % number = 1, number is probably prime
        //Repeat num_tests times
        int result = 0;
        for (int i = 0; i < num_tests; i++)
        {
            result = safePow(a, number-1) % number;
            if (result == -1)
            {
                cout << "Error (fermatTest): Could not compute " << a << "^" << (number-1) << ".\n";
                return -1;
            }
            else if (result != 1)
                return 0;
            a = rand() % (number - 2) + 2;
        }

        return 1;
}

int millerRabin(int number)
{
    int a = rand() % number + 1;
    int s = 0;
    int d = number-1;

    while (d % 2 == 0)
    {
        s++;
        d /= 2;
    }

    int result1 = safePow(a, d) % number;
    int result2 = 0;
    if (result1 == -1)
    {
        cout << "Error (millerRabin): Could not compute " << a << "^" << d << ".\n";
        return -1;
    }
    else if (result1 == 1)
        return 1;

    for (int r = 0; r <= s - 1; r++)
    {
        //There has to be a better way to detect if safePow returned an error.
        //Throw exception?
        result1 = safePow(2, r);
        result2 = safePow(a, result1 * d);
        if (result1 == -1 || result2 == -1)
        {
            cout << "Error (millerRabin): Exponention too big.\n";
            return -1;
        }

        if (safePow(a, safePow(2, r) * d) % number == number - 1)
            return 1;
    }
    return 0;
}

int main()
{
    int number = 0;
    int num_tests = 4;

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
    test_names[2] = "Fermat's Test";
    test_names[3] = "Miller-Rabin";

    //Create an array for test results
    int test_results[num_tests];
    test_results[0] = trialDivision(number);
    test_results[1] = wilsonsTheorem(number);
    test_results[2] = fermatTest(number, 20);
    test_results[3] = millerRabin(number);

    //Print test results
    cout << "\nResults:\n";
    for (int i = 0; i < num_tests; i++)
    {
        cout << test_names[i] << ": ";

        if(test_results[i] == 1)
            cout << number << " is prime.\n";
        else if (test_results[i] == 0)
            cout << number << " is not prime.\n";
        else
            cout << "Error.\n";
    }
    cout << "\n";

    return 0;
}
