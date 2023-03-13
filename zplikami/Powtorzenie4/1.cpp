#include <bits/stdc++.h>
#include <cstdlib>
#include <string>

using namespace std;

int tab[2000];
int najwieksza = 0;
int najmniejsza = 0;

bool bCzyPierwsza(int n)
{
    if(n<2) return false;

	for(int i=2;i*i<=n;i++)
	{
        if(n%i==0) return false;
	}

	return true;
}

int A()
{
    int pierwsze = 0;
    for (int i = 0; i < 2000; i++)
    {
        if(bCzyPierwsza(tab[i]) == true) pierwsze++;
    }

    return pierwsze;
}

void B()
{
    for (int i = 0; i < 2000; i++)
    {
        if(bCzyPierwsza(tab[i]) == true && najwieksza < tab[i]) najwieksza = tab[i];
        if(bCzyPierwsza(tab[i]) == true && najmniejsza > tab[i] || bCzyPierwsza(najmniejsza) == false) najmniejsza = tab[i];
    }
}

void C()
{
    int blizniacze = 0;
    int i = 0;
    while(i < 2000)
    {
        if(bCzyPierwsza(tab[i]) && bCzyPierwsza(tab[i + 1]) && abs(tab[i] - tab[i + 1]) == 2)
        {
            cout << "liczby blizniacze: " << tab[i] << ", " << tab[i+1] << endl;
            blizniacze++;
        }
        i++;
    }
    cout << "wszystkich liczb blizniaczych jest: " << blizniacze << endl;
}

int main()
{
    ifstream plik;
    plik.open("dane_6.txt");

    for(int i = 0; i < 2000; i++) plik >> tab[i];

    cout << "liczb pierwszych jest: " << A() << endl;
    B();
    cout << "najmniejsza: " << najmniejsza << endl << "najwieksza: " << najwieksza << endl;
    C();
}
