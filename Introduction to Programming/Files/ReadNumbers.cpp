#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int number = 0;
    ifstream infile;
    infile.open("input.txt");

    infile >> number;
    cout << number * number << endl;
    infile >> number;
    cout << number * number << endl;
    infile >> number;
    cout << number * number << endl;
    infile >> number;
    cout << number * number << endl;

    infile.close();

    return 0;
}
