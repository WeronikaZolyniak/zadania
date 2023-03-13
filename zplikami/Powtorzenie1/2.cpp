#include <bits/stdc++.h>

using namespace std;

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

    sort(tab, tab + 1001);

    cout << tab[500];
}
