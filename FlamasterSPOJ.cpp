#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

string SkrocWyraz(string wyraz)
{
    string nowywyraz;
    nowywyraz += wyraz[0];
    int licznik = 1;
    for(int i = 1; i < wyraz.length(); i++)
    {
        if(wyraz[i] != wyraz[i - 1]) nowywyraz += wyraz[i];
        else if (i == wyraz.length()-1 || wyraz[i] != wyraz[i + 1])
        {
            licznik++;
            if (licznik > 2) nowywyraz += to_string(licznik);
            else nowywyraz += wyraz[i];
            licznik = 1;
        }
        else licznik++;
    }
    return nowywyraz;
}


int main()
{
    int ilosc;
    cin >> ilosc;
    string wyraz;
    for(int i = 0; i < ilosc; i++)
    {
        cin >> wyraz;
        cout << SkrocWyraz(wyraz) << endl;
    }

}
