#include <bits/stdc++.h>
using namespace std;



int main()
{
    int iloscrzutow;
    cin >> iloscrzutow;

    srand(time(NULL));

    for (int i = 1; i <= iloscrzutow; i++)
    {
        int liczba = (rand() % 6) + 1;
        string krzyzyki;
        for (int n = 0; n < liczba; n++)
        {
            krzyzyki = krzyzyki + "#";
        }
        cout << i << ": " << krzyzyki << endl;

    }
}
