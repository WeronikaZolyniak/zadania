#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream plik;
    plik.open("zestaw.txt");

    int najwieksza;
    plik >> najwieksza;

    int najmniejsza = najwieksza;

    for(int i = 1; i < 1001; i++)
    {
        int temp;
        plik >> temp;
        if(temp < najmniejsza) najmniejsza = temp;
        if(temp > najwieksza) najwieksza = temp;
    }

    cout << "Najwieksza: " << najwieksza << endl;
    cout << "Najmniejsza: " << najmniejsza << endl;
}
