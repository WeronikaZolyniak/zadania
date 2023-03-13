#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int liczby[1000];

void A()
{
    int najwieksza = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(liczby[i] > najwieksza && liczby[i] % 2 == 0) najwieksza = liczby[i];
    }
    cout << " A: Najwieksza parzysta: " << najwieksza << endl;
}

void B()
{
    cout << "B: palindromiczne liczby: " << endl;
    for(int i = 0; i < 1000; i++)
    {
        string sliczba = to_string(liczby[i]);
        int j = sliczba.length() - 1;
        string odwrotnie;
        while(j >= 0)
        {
            odwrotnie += sliczba[j];
            j -= 1;
        }
        if (sliczba == odwrotnie) cout << sliczba << endl;
    }

}

void C()
{
    int ogolnasuma = 0;
    cout << "C: Liczby o sumie cyfr 30 " << endl;
    for(int i = 0; i < 1000; i++)
    {
        int sumacyfr = 0;
        string sliczba = to_string(liczby[i]);
        for(int j = 0; j < sliczba.length(); j++)
        {
            sumacyfr += sliczba[j] - '0';
            ogolnasuma += sliczba[j] - '0';
        }
        if(sumacyfr == 30) cout << sliczba <<endl;
    }
    cout << "Ogolna suma: " << ogolnasuma << endl;
}

int main()
{
    ifstream plik;
    plik.open("liczby.txt");
    for(int i = 0; i < 1000; i++) plik >> liczby[i];
    A();
    B();
    C();
    return 0;
}
