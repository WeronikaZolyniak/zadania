#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

int silnia(int n)
{
    if(n<2) return 1;

    return n*silnia(n-1);
}

double cosinus(double x)
{
    double wynik = 1;
    double element = pow(x,2) / silnia(2);
    for(int i = 2; element > 0.0001; i++)
    {
        wynik = wynik - element;
        element = pow(x, 2* i) / silnia(2 * i);
    }


}

int main()
{
    double x;
    cin >> x;
    if (x > 0) cout << cosinus(x);
}
