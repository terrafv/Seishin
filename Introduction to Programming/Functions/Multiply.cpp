#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int multiply (int a, int b)
{
    return a * b;
}

int ** multiply (int **m1, int m1rows, int m1cols, int **m2, int m2rows, int m2cols)
{
    if (m1cols != m2rows)
        return nullptr;

    int ** result = new int * [m1rows];
    for (int i = 0; i < 3; i++)
        result[i] = new int[3];

    for(int m3row = 0; m3row < m1rows; m3row++)
        for (int m3col = 0; m3col < m2cols; m3col++)
        {
            int sum = 0;
            for (int x = 0; x < m1cols; x++)
                sum += m1[m3row][x] * m2[x][m3col];
            cout << "Sum = " << sum << endl;
            result[m3row][m3col] = sum;
        }

    return result;
}

int main()
{
    srand(time(0));

    int ** m1 = new int * [3];
    for (int i = 0; i < 3; i++)
        m1[i] = new int[3];

    int ** m2 = new int * [3];
    for (int i = 0; i < 3; i++)
        m2[i] = new int[3];

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            m1[x][y] = rand() % 100;
            m2[x][y] = rand() % 100;
        }
    }

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
            cout << m1[x][y] << " ";
        cout << endl;
    }

    cout << "\n\n";

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
            cout << m2[x][y] << " ";
        cout << endl;
    }

    int ** m3 = multiply(m1, 3, 3, m2, 3, 3);

    cout << "\n\n";

    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
            cout << m3[x][y] << " ";
        cout << endl;
    }

    int * m4 = new int[2][2];
}

