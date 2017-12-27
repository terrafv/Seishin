//This program tests whether or not a series of numbers is monotonically increasing.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //Open the file
    ifstream infile;
    infile.open("Numbers.txt");

    //Check if the file opened correctly
    if (infile.fail())
    {
        cout << "Error opening the file\n";
        return 0;
    }

    int numLines = 0, seqLength = 0;

    //Get the number of sequences in the file
    infile >> numLines;

    //Create a pointer to our array
    int * sequence;

    //Process each line
    for (int x = 0; x < numLines; x++)
    {
        //Get the length of the line
        infile >> seqLength;

        //Dynamically allocate memory for the new sequence
        sequence = new int[seqLength];

        //Read the sequence into the array
        for (int y = 0; y < seqLength; y++)
            infile >> sequence[y];

        //Scan each pair of consecutive elements
        for (int y = 0; y < seqLength-1; y++)
        {
            //If two consecutive elements are decreasing, the entire array is bad
            if (sequence[y] > sequence[y+1])
            {
                cout << "No\n";
                break;
            }

            //If this is the last iteration, the array is good
            if (y == seqLength - 2)
                cout << "Yes\n";
        }

        //Delete the array
        delete [] sequence;
    }

    //Point sequence to null and close the file
    sequence = nullptr;
    infile.close();

    return 0;
}
