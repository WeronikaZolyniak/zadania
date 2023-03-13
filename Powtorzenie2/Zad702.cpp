#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

struct dwojka
{
    string napis1;
    string napis2;
};

dwojka dwojki[200];

void A()
{
    cout << "A: " << endl;
    int liczba = 0;
    for(int i = 0; i < 200; i++)
    {
        if(dwojki[i].napis1.length() >= dwojki[i].napis2.length() * 3 ||
        dwojki[i].napis2.length() >= dwojki[i].napis1.length() * 3)
        {
            if(liczba == 0 ) cout << dwojki[i].napis1 << "     " << dwojki[i].napis2 << endl;
            liczba++;
        }
    }
    cout << "Ilosc: " << liczba << endl;
}

bool CzyZawarty(string napis1, string napis2)
{
    if(napis1.length() > napis2.length()) return false;
    else{
        for(int i = 0; i < napis1.length(); i++)
        {
            if(napis1[i] != napis2[i]) return false;
        }
        return true;
    }
}

void B()
{
    cout << "B: " << endl;
    int licznik = 0;
    for(int i = 0; i < 200; i++)
    {
        if(CzyZawarty(dwojki[i].napis1, dwojki[i].napis2))
        {
            cout << dwojki[i].napis1 << "    " << dwojki[i].napis2 << endl;
            licznik++;
        }

    }
    cout << "Ilosc: " << licznik << endl;
}

int dlzak(string napis1, string napis2)
{
    int licznik = 0;
    int i1 = napis1.length() - 1;
    int i2 = napis2.length() - 1;
    while(napis1[i1] == napis2[i2])
    {
        licznik++;
        i1 = i1 - 1;
        i2 = i2 - 1;
    }
    return licznik;
}

void C()
{
    cout << "C: " << endl;
    int maks = 0;
    for(int i = 0; i < 200; i++)
    {
        if(dlzak(dwojki[i].napis1, dwojki[i].napis2) > maks)
        {
            maks = dlzak(dwojki[i].napis1, dwojki[i].napis2);
        }
    }
    for(int i = 0; i < 200; i++)
    {
        if(dlzak(dwojki[i].napis1, dwojki[i].napis2) == maks)
        {
            cout << dwojki[i].napis1 << "   " << dwojki[i].napis2 << endl;
        }
    }
    cout << "maks: " << maks << endl;
}

int main()
{
    ifstream plik;
    plik.open("napisy.txt");

    for(int i = 0; i < 200; i++)
    {
        plik >> dwojki[i].napis1 >> dwojki[i].napis2;
    }
    A();
    B();
    C();
}
