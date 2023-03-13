#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    ifstream plik;
    plik.open("duze_liczby.txt");
    long srednia = 0;
    long reszta = 0;
    for(int i = 0; i < 1000; i++)
    {
        long linia;
        plik >> linia;
        srednia += linia /1000;
        reszta += linia % 1000;
        if(reszta >= 1000)
        {
            srednia += 1;
            reszta = reszta - 1000;
        }

    }

    cout << "Srednia to: " << srednia << " i " << reszta << "/1000" << endl;
}
