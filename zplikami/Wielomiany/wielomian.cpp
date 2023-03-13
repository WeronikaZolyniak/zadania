#include <bits/stdc++.h>
#include <string>
using namespace std;

double horner(double tab[], int sizem, double x)
{
    double y = tab[0];
    for(int i = 1; i < sizem; i++)
    {
        y = y*x + tab[i];
    }
    return y;
}

int main()
{
    ifstream plik;
    plik.open("wielomiany.txt");

    for(int i = 0; i < 200; i++)
    {
        int stopien;
        plik >> stopien;
        double *wspolczynniki = new double[stopien + 1];
        for(int j = 0; j < stopien + 1; j++)
        {
            plik >> wspolczynniki[j];
        }
        double argument;
        plik >> argument;

        cout << horner(wspolczynniki,stopien + 1,argument) << endl;

        delete [] wspolczynniki;
    }
}
