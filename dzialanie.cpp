#include <iostream>
#include <math.h>
using namespace std;


float Oblicz(int x);


int main()
{
 int x;
 cin >> x;

 if (x == 2) cout << "Program nie moze wyliczyc wyniku.";
 else cout << Oblicz(x);
}

double Oblicz(int x)
{
    return (sqrt(3) - pow(x,5)) / ((-2) + x);
}
