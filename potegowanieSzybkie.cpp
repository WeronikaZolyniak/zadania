#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

long pot_szybkie(long x, long n)
{
    long a;
    if(n == 0) return 1;

    if(n % 2 == 1) return x * pot_szybkie(x, n-1);
    else
    {
        a = pot_szybkie(x, n/2);
        return a * a;
    }
}

int main()
{
    long x,n;
    cin >> x;
    cin >> n;
    cout << pot_szybkie(x,n);
}
