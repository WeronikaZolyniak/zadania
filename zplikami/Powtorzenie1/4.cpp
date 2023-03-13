#include <bits/stdc++.h>

using namespace std;




int main()
{
    ifstream plik;
    plik.open("zestaw.txt");
    int lnpierwsze = 0;
    int tab[1001];
    for (int i = 0; i < 1001; i++)
    {
        int temp;
        plik >> temp;
        tab[i] = temp;
    }

    for(int i = 0; i < 1001; i++)
    {
        for(int d = 1; d < tab[i]; d++)
        {
            if (tab[i] < 2) {lnpierwsze++;}
            else if (tab[i] % d == 0 && d != 1 && d != tab[i]){lnpierwsze++;}
        }
    }

    cout << 1000 - lnpierwsze;
}
