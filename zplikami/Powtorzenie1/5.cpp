#include <bits/stdc++.h>

using namespace std;



int NWD(int a, int b)
{
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }

    return a;
}


int main()
{
    ifstream plik;
    plik.open("zestaw.txt");

    int tab[1001];

    for (int i = 0; i < 1001; i++)
    {
        int temp;
        plik >> temp;
        tab[i] = temp;
    }

    int nwd = NWD(tab[0], 2358);
    int liczba;

    for(int i = 1; i < 1001; i++)
    {
        if(NWD(tab[i], 2358) > nwd)
        {
            liczba = tab[i];
            nwd = NWD(tab[i], 2358);
        }
    }

    cout << liczba;
}
