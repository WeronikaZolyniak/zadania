#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
#include<string.h>
using namespace std;

string ciagi[1000];

void A()
{
    cout << "A: " << endl;
    int licznik = 0;
    for(int i = 0; i < 1000; i++)
    {
        string odwrotny;
        int j = ciagi[i].length() - 1;
        while(j >= 0)
        {
            odwrotny += ciagi[i][j];
            j--;
        }
        if(odwrotny == ciagi[i])
        {
            licznik++;
            if(ciagi[i].length() == 8)
            {
                cout << ciagi[i] << endl;
            }
        }
    }
    cout << "Ilosc: " << licznik << endl;
}

long szesnadzies(string szes)
{
    long suma = 0;
    long potega = 1;

    for(int i = szes.length() - 1; i >= 0; i--)
    {
        suma += ((szes[i] - 'A') + 10) * potega;
        potega = potega * 16;
    }

    return suma;
}

void B()
{
    cout << "B: " << endl;
    long minl = szesnadzies(ciagi[0]);
    int indexmin = 0;
    long maxl = szesnadzies(ciagi[0]);
    int indexmax = 0;
    for(int i = 1; i < 1000; i++)
    {
        if(szesnadzies(ciagi[i]) < minl)
        {
            minl = szesnadzies(ciagi[i]);
            indexmin = i;
        }
        if(szesnadzies(ciagi[i]) > maxl)
        {
            maxl = szesnadzies(ciagi[i]);
            indexmax = i;
        }
    }
    cout << "Najmniejsza: " << ciagi[indexmin] << "   " << minl << endl;
    cout << "Najwieksza: " << ciagi[indexmax] << "   " << maxl << endl;
}

void C()
{
    sort(ciagi, ciagi + 1000);
    cout << "C: " << endl;
    for(int i = 0; i < 5; i++) cout << ciagi[i] << endl;

    cout << ciagi[995] << endl;
    cout << ciagi[996] << endl;
    cout << ciagi[997] << endl;
    cout << ciagi[998] << endl;
        cout << ciagi[999] << endl;
}

bool Czyskl(string ciag)
{
    int Ilosc[6] = {0,0,0,0,0,0};
    if(ciag.length() != 6) return false;
    else{
        for(int i = 0; i < 6; i++)
        {
            Ilosc[(ciag[i]- 'A')] += 1;
        }
    }
    for(int i = 0; i < 6; i++)
    {
        if(Ilosc[i] != 1) return false;
    }
    return true;
}

void D()
{
    int ilosc = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(Czyskl(ciagi[i])) ilosc++;
    }
    cout << "D: " << ilosc << endl;
}

int main()
{
    ifstream plik;
    plik.open("ciagi.txt");

    for(int i = 0; i < 1000; i++)
    {
        plik >> ciagi[i];
    }
    A();
    B();
    C();
    D();

}
