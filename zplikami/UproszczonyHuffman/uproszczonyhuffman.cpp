#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <algorithm>
using namespace std;


struct litery
{
    char c;
    int n;
    string k;
};

litery tab[12];
string formula;

bool sortuj(litery l1, litery l2)
{
    return l1.n > l2.n;
}

bool sortuj2(litery l1, litery l2)
{
    return l1.c < l2.c;
}

string naBin(int n, int d)
{
    string s;
    while(n > 0)
    {
        s = to_string(n % 2) + s;
        n = n / 2;
    }
    while(s.size() < d) s = "0" + s;
    return s;
}

int main()
{
    ifstream plik;
    plik.open("formula.txt");
    plik >> formula;
    plik.close();

    for(int j = 0; j < 12; j++)
    {
        tab[j].c = (char)('A' + j);
        tab[j].n = 0;

    }
    for(int i = 0; i < formula.size(); i++)
    {
        int litera = formula[i] - 'A';
        tab[litera].n++;
    }
    sort(tab, tab+12, sortuj);

    for(int i = 0; i < 4; i++)
    {
        tab[i].k = naBin(i,3);
    }
    for(int i = 4; i < 12; i++)
    {
        tab[i].k = "1" + naBin(i - 4, 3);
    }
    sort(tab, tab + 12, sortuj2);

    string kod;
    for(char l: formula)
    {
        kod += tab[l - 'A'].k;
    }
    ofstream w("kod_formuly.txt");
    w << kod << endl;

    // stpoien kompresji - formula.size / (kod.size/8)
    return 0;
}
