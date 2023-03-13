#include <bits/stdc++.h>
#include <string>

using namespace std;

int najwieksza;
string snajwieksza;
int najmniejsza;
string snajmniejsza;

int CyfraNaLiczbe(char c)
{
    if(c >= '0' && c <= '9') return c - '0'; // ascii
    return c - 'A' + 10;
}

int ToInt(string s, int p)
{
    int liczba = 0;
    int potega = 1;
    int i = s.size() - 1;

    while(i >= 0)
    {
        liczba = liczba + CyfraNaLiczbe(s[i]) * potega;
        potega = potega * p;
        i = i - 1;
    }

    return liczba;

}

void B(string linia)
{
    if(ToInt(linia, 16) > najwieksza)
    {
        najwieksza = ToInt(linia, 16);
        snajwieksza = linia;
    }

    if(ToInt(linia, 16) < najmniejsza)
    {
        najmniejsza = ToInt(linia, 16);
        snajmniejsza = linia;
    }

}

int main()
{
    ifstream plik;
    plik.open("ciagi.txt");

    string linia;

    plik >> linia;
    najmniejsza = ToInt(linia,16);
    snajmniejsza = linia;
    najwieksza = ToInt(linia,16);
    snajwieksza = linia;


    while(plik >> linia)
    {
        B(linia);
    }

    cout << "najwieksza: " << najwieksza << ", " << snajwieksza << endl;
    cout << "najmniejsza: " << najmniejsza << ", " << snajmniejsza;
}
