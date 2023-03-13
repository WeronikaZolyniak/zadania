#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int liczba1;
    int liczba2;

    cout << "Wpisz dzielna: ";
    cin >> liczba1;
    cout << "Wpisz dzielnik: ";
    cin >> liczba2;

    if (liczba1 % liczba2 == 0)
    {
        cout << "Liczby dziela sie przez siebie bez reszty.";
    }
    else
    {
        cout << "Liczby dziela sie przez siebie z reszta.";
    }

    return 0;
}
