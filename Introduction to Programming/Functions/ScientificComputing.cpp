//This is the solution to Assignment 1. It should be bug-free,
//but if you find any mistakes, let me know ASAP. -Josh

#include <iostream>
#include <iomanip>
using namespace std;

float roadTrip (int gallons, float gasPrice, float mpg, int distance)
{
    return ((distance / mpg) - gallons) * gasPrice;
}

float circumference (int radius)
{
    return 2 * radius * 3.14;
}

float area (int radius)
{
    return radius * radius * 3.14;
}

double force ()
{
    double g = 6.674E-11;
    double mass1 = 1.99E30;
    double mass2 = 5.97E24;
    double d = 1.5E11;
    double force = g*((mass1*mass2)/(d*d));

    return force;
}

int main()
{
    cout << "It will cost $" << setprecision(3) << roadTrip(1, 2.10, 24.3, 140) << " to complete the trip." << endl;
    cout << "The circumference is " << circumference(5) << endl;
    cout << "The area is " << area(5) << endl;
    cout << "The gravitational force between the sun and the Earth is " << force() << " Newtons." << endl;

    return 0;
}
