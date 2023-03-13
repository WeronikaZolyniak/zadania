#include <bits/stdc++.h>
using namespace std;



int main()
{
    int ilosc;
    cin >> ilosc;

    float srednia = 0;

    for (int i = 0; i < ilosc; i++)
    {
        srand(time(NULL));
        srednia += rand() % 10000;

    }
    srednia = srednia / ilosc;

    cout << srednia;

    return 0;
}

