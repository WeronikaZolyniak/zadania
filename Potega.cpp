#include <iostream>
#include <cstdio>
using namespace std;

int podstawa = 0;
int wykladnik = 0;
int liczba;

int main()
{
    cout << "Wpisz liczbe calkowita, ktora chcesz spotegowac: ";
    cin >> podstawa;
    liczba = podstawa;
    cout << "Wpisz wykladnik potegi: ";
    cin >> wykladnik;

    if(wykladnik == 0)
    {
        liczba = 1;
    }
    else
    {
        for(int i = 1; i < wykladnik; i++)
        {
            liczba = liczba * podstawa;
        }
    }
    cout << liczba;

    return 0;
}
