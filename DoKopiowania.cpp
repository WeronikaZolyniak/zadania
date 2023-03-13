#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

long long pot_szybkie(long long a, long long n)
{
	long long w = 1;

	while(n>0)
	{
		if (n%2 == 1)
			w *= a;

		a= a % 10 * a % 10;
		n/=2;

		w = w % 10;
	}
	return w;
}

int main()
{
    int ilosc;
    cin >> ilosc;
    long long x,n;
    for(int i = 0; i < ilosc; i++)
    {
        cin >> x;
        cin >> n;
        cout << pot_szybkie(x,n) << endl;
    }

}
