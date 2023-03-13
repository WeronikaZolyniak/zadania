#include <bits/stdc++.h>
#include <string>

using namespace std;

bool bCzyPierwsza(int n)
{
    if(n<2) return false;

	for(int i=2;i*i<=n;i++)
	{
        if(n%i==0) return false;
	}

	return true;
}

int main()
{
    ifstream plik;
    plik.open("liczby.txt");

    int tab[500];

    for(int i = 0; i < 500; i++) plik >> tab[i];

    for(int i = 0; i < 500; i++)
    {
        for(int n = 2; n < 1000; n++)
        {
            if(bCzyPierwsza(n))
            {
                if(pow(n, 2) == tab[i]) cout << tab[i] << endl;
            }
        }
    }
}

