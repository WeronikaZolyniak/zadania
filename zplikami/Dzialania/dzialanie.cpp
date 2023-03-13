#include <bits/stdc++.h>
#include <string>

using namespace std;

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

int main()
{
    ifstream plik;
    plik.open("dzialania.txt");

    int wynik = 0;
    string s;
    int l;
    char z;

    plik >> s >> l;

    wynik = ToInt(s, l);

    for(int i = 0; i < 50;i++)
    {
        plik >> z >> s >> l;

        if (z == '+') wynik += ToInt(s,l);
        else if (z == '-') wynik = wynik - ToInt(s,l);
        else if (z == '*') wynik = wynik * ToInt(s,l);
        else if (z == '%') wynik = wynik % ToInt(s,l);
    }

    cout << wynik << endl;

}

