#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("output.txt");

    outfile << "Correct\n";
    outfile << "Horse\n";
    outfile << "Battery\n";
    outfile << "Staple\n";

    outfile.close();

    return 0;
}
