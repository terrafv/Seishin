#include <iostream>
using namespace std;

int main()
{
    int count = 0;

    for (int d1 = 1; d1 <= 6; d1++)
        for (int d2 = 1; d2 <= 6; d2++)
            if (d1 + d2 == 7)
                count++;

    cout << "The probability of rolling 7 with 2 6-sided dice is " << (float)count / 36 << endl;

    count = 0;

    for (int d1 = 1; d1 <= 20; d1++)
        for (int d2 = 1; d2 <= 20; d2++)
            for (int d3 = 1; d3 <= 20; d3++)
                if (d1 + d2 + d3 == 7)
                    count++;

    cout << "The probability of rolling 7 with 3 20-sided dice is " << (float)count / (20*20*20) << endl;
    return 0;
}
