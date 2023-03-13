#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <algorithm>
using namespace std;

int liczby[1000];

void A()
{
    int ilosc = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(to_string(liczby[i]).length() > 5) ilosc++;
    }
    cout << "A: wiecej niz 5 cyfr ma " << ilosc << " liczb." << endl;
}

void B()
{
    int liczbaznajwiekszym;
    int najwiekszyil = 0;
    for(int i = 0; i < 1000; i++)
    {
        string sliczba = to_string(liczby[i]);
        int il = 1;
        for(int j = 0; j < sliczba.length(); j++)
        {
            il = il * (sliczba[j] - '0');
        }
        if(najwiekszyil < il)
        {
            liczbaznajwiekszym = liczby[i];
            najwiekszyil = il;
        }
    }

    cout << "B: najwiekszy iloczyn cyfr ma liczba: " << liczbaznajwiekszym << " , wynosi on: " << najwiekszyil << endl;
}

int main()
{
    ifstream plik;
    plik.open("liczby.txt");

    for(int i = 0; i < 1000; i++) plik >> liczby[i];

    A();
    B();
    return 0;
}
