#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream plik;
    plik.open("zestaw.txt");

    int suma = 0;

    int tab[1001];

    for (int i = 0; i < 1001; i++)
    {
        int temp;
        plik >> temp;
        tab[i] = temp;
    }

    for(int i = 0; i < 1001; i++) suma = suma + tab[i];

    float srednia = suma / 1001.0;

    printf("Srednia %.2f;  ", srednia);

    int roznica = srednia - tab[0];
    int najblizsza;

    for (int i = 0; i < 1001; i++)
    {
        int temp;
        if (tab[i] < srednia) temp = srednia - tab[i];
        else temp = tab[i] - srednia;

        if (roznica > temp)
        {
            roznica = temp;
            najblizsza = tab[i];
        }
    }

    cout << "najblizsza sredniej: " << najblizsza << endl;

}
