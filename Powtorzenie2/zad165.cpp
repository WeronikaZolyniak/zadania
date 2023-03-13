#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <algorithm>
using namespace std;


struct trojka
{
    int l1;
    int l2;
    int l3;
};

trojka trojki[1000];

int A()
{
    int ilosc = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(trojki[i].l1 < trojki[i].l2 && trojki[i].l2 < trojki[i].l3) ilosc++;
    }
    return ilosc;
}

int NWD(int a, int b)
{
    while(a!=b)
       if(a>b)
           a-=b;
       else
           b-=a;
    return a;
}

int B()
{
    int sumanwd = 0;
    for(int i = 0; i < 1000; i++)
    {
        sumanwd += NWD(NWD(trojki[i].l1, trojki[i].l2), trojki[i].l3);
    }
    return sumanwd;
}

void C()
{
    int ilosc35 = 0;
    int najwiekszasuma = 0;
    int iloscnaj = 0;
    for(int i = 0; i < 1000; i++)
    {
        int sumacyfr = 0;
        string l1 = to_string(trojki[i].l1);
        for(int j = 0; j < l1.length(); j++)
        {
            sumacyfr += l1[j] - '0';
        }
        string l2 = to_string(trojki[i].l2);
        for(int j = 0; j < l2.length(); j++)
        {
            sumacyfr += l2[j] - '0';
        }
        string l3 = to_string(trojki[i].l3);
        for(int j = 0; j < l3.length(); j++)
        {
            sumacyfr += l3[j] - '0';
        }
        if(sumacyfr == 35) ilosc35++;
        if(najwiekszasuma < sumacyfr)
        {
            najwiekszasuma = sumacyfr;
            iloscnaj = 1;
        }
        else if(najwiekszasuma == sumacyfr)
        {
            iloscnaj++;
        }
    }

    cout << "C: " << endl;
    cout << "Liczba wierszy dla ktorych suma = 35: " << ilosc35 << endl;
    cout << "Najwieksza suma cyfr: " << najwiekszasuma << endl;
    cout << "Ilosc wystapien naj sumy: " << iloscnaj << endl;
}


int main()
{
    ifstream plik;
    plik.open("liczby.txt");

    for(int i = 0; i < 1000; i++)
    {
            plik >> trojki[i].l1 >> trojki[i].l2 >> trojki[i].l3;
    }

    cout << "A: " << A() << endl;
    cout << "B: " << B() << endl;
    C();
}
