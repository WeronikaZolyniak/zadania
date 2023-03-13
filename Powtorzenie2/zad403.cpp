#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string pesele[1000];

void A()
{
    int liczbakobiet = 0;
    int liczbamezczyzn = 0;
    for(int i = 0; i < 1000; i++)
    {
        int cyfra = pesele[i][9] - '0';
        if(cyfra % 2  == 0) liczbakobiet++;
        else liczbamezczyzn++;

    }
    cout << "Liczba kobiet: " << liczbakobiet << endl;
    cout << "Liczba mezczyzn: " << liczbamezczyzn << endl;
}

void B()
{
    int liczba = 0;
    for(int i = 0; i < 1000; i++)
    {
        int mscUr;
        if (pesele[i][2] == '2' || pesele[i][2] == '0')
        {
            mscUr = pesele[i][3] - '0';
        }
        else if (pesele[i][2] == '3' || pesele[i][2] == '1')
        {
            mscUr = pesele[i][3] - '0' + 10;
        }
        if(mscUr == 11) liczba++;
    }
    cout << "Ilosc osob urodzonych w listopadzie: " << liczba << endl;
}

void C()
{
    int blednepesele = 0;
    for(int i = 0; i < 1000; i++)
    {
        int suma = int(pesele[i][0]) + 3 * int(pesele[i][1]) + 7 * int(pesele[i][2]) +
        9 * int(pesele[i][3]) + int(pesele[i][4]) + 3 * int(pesele[i][5]) + 7 * int(pesele[i][6])
        + 9 * int(pesele[i][7]) + int(pesele[i][8]) + 3 * int(pesele[i][9]) + int(pesele[i][10]);

        if(suma % 10 != 0) blednepesele++;
    }
    cout << "Bledne pesele: " << blednepesele << endl;
}

int main()
{
    ifstream plik;
    plik.open("dane.txt");

    for(int i = 0; i < 1000; i++) plik >> pesele[i];
    A();
    B();
    C();
}
