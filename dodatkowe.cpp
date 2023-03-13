#include <bits/stdc++.h>
using namespace std;



int main()
{
    int iloscrzutow;
    cin >> iloscrzutow;

    int Tablica[6] = {0,0,0,0,0,0};

    srand(time(NULL));

    for (int i = 1; i <= iloscrzutow; i++)
    {
        int liczba = rand() % 7;
        if (liczba == 1)   Tablica[0] = Tablica[0] + 1;
        else if (liczba == 2) Tablica[1] = Tablica[1] + 1;
        else if (liczba == 3) Tablica[2] = Tablica[2] + 1;
        else if (liczba == 4) Tablica[3] = Tablica[3] + 1;
        else if (liczba == 5) Tablica[4] = Tablica[4] + 1;
        else Tablica[5] = Tablica[5] + 1;
    }

    int i = 0;
    int n = 1;
    while(n < 7)
    {
        cout << n << ". ";

        while (i <= Tablica[n - 1])
        {
            cout << "#";
            i += 10;
        }
        i = 0;
        cout << endl;
        n++;
    }
}
