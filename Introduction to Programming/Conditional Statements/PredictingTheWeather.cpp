#include <iostream>
using namespace std;

int main()
{
    int temp, precip, wind;
    cout << "Enter the temperature in Fahrenheit (0-120):" << endl;
    cin >> temp;
    cout << "Enter the chance of precipitation (0-100): " << endl;
    cin >> precip;
    cout << "Enter the wind speed (0-100): " << endl;
    cin >> wind;

    bool t = temp > 32;
    bool p = precip > 50;
    bool w = wind > 15;

    //The following two if/else if/else blocks are structured differently,
    //but logically they express the same thing.
/*
    if(t && p && w)
        cout << "It will storm today" << endl;
    else if(t && p && !w)
        cout << "It will rain today" << endl;
    else if(t && !p && w)
        cout << "There will be a warm breeze today" << endl;
    else if(t && !p && !w)
        cout << "It will be hot today" << endl;
    else if(!t && p && w)
        cout << "There will be a blizzard today" << endl;
    else if(!t && p && !w)
        cout << "It will snow today" << endl;
    else if(!t && !p && w)
        cout << "There will be a cool breeze today" << endl;
    else
        cout << "It will be cold today" << endl;
        */

    if(t)
    {
        if(p)
        {
            if(w)
                cout << "It will storm today" << endl;
            else
                cout << "It will rain today" << endl;
        }
        else
        {
            if(w)
                cout << "There will be a warm breeze today" << endl;
            else
                cout << "It will be hot today" << endl;
        }
    }
    else
    {
        if(p)
        {
            if(w)
                cout << "There will be a blizzard today" << endl;
            else
                cout << "It will snow today" << endl;
        }
        else
        {
            if(w)
                cout << "There will be a cool breeze today" << endl;
            else
                cout << "It will be cold today" << endl;
        }
    }

    return 0;
}
