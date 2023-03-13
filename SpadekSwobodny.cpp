#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

float ObliczWysokosc(float t)
{
    return (9.81 * pow(t,2)) / 2;
}

int main()
{
    float t;
    cout << "Podaj czas spadku w sekundach: ";
    cin >> t;
    cout << "Droga przebyta przez cialo w spadku swobodnym to " << ObliczWysokosc(t) << " m.";
}
