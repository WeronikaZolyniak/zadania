#include <bits/stdc++.h>
#include <string>

using namespace std;

string Tab[1000];

int A()
{
    int iloscA = 0;
    for(int i = 0; i < 1000; i++)
    {
        string linia = Tab[i];
        for(int n = 0; n < linia.length(); n++)
        {
            if(linia[n] == 'a') iloscA++;
        }
    }

    return iloscA;
}

bool CzyJestPierwsza(int liczba)
{
    for(int i = 1; i < liczba; i++)
    {
        if( liczba % i == 0 && i != 1 && i != liczba) return false;
    }
    return true;
}

int B()
{
    int iloscPierwszychASCII = 0;
    for(int i = 0; i < 1000; i++)
    {
        string linia = Tab[i];
        int sumaASCII = 0;
        for(int n = 0; n < linia.length(); n++)
        {
            sumaASCII = sumaASCII + (int)linia[n];
        }
        if(CzyJestPierwsza(sumaASCII)) iloscPierwszychASCII++;
    }
    return iloscPierwszychASCII;
}

void C()
{
    for(int i = 0; i < 1000; i++)
    {
        string linia = Tab[i];
        string liniaodtylu;
        int n = linia.length() - 1;
        while( n >= 0)
        {
            liniaodtylu = liniaodtylu + linia[n];
            n = n-1;
        }
        if (linia == liniaodtylu) cout << linia << endl;
    }
}

int main()
{
    ifstream plik;
    plik.open("stringi.txt");

    for(int i = 0; i < 1000; i++) plik >> Tab[i];

    cout << "Ilosc liter a w pliku: " << A() << endl;
    cout << "Ilosc pierwszych kodow ASCII: " << B() << endl;
    C();

    return 0;
}
