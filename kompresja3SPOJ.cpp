#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

string wyrazy[1000];

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
            if (licznik > 2) nowywyraz = nowywyraz + '*' + to_string(licznik);
            else nowywyraz += wyraz[i];
            licznik = 1;
        }
        else licznik++;
    }
    return nowywyraz;
}

string kompresja()
{
    string nowewyrazy = SkrocWyraz(wyrazy[0]);
    int licznik = 1;
    for(int i = 1; i < 1000; i++)
    {
        if(wyrazy[i] != wyrazy[i - 1]) nowewyrazy = nowewyrazy + " " + SkrocWyraz(wyrazy[i]);
        else if (wyrazy[i] != wyrazy[i + 1])
        {
            licznik++;
            nowewyrazy = nowewyrazy + '/' + to_string(licznik) + " ";
            licznik = 1;
        }
        else licznik++;

    }
    return nowewyrazy;
}

string dekompresja()
{
    string nowewyrazy;
    for(int i = 0; i < 1000; i++)
    {
        string dekwyraz;
        for(int j = 0; j < wyrazy[i].length(); j++)
        {
            if(wyrazy[i][j] == '*')
            {
                int liczbaznaku =  '0' + wyrazy[i][j + 1];
                for(int m = 0; m < liczbaznaku - 1; m++)
                {
                     dekwyraz += wyrazy[i][j-1];
                }
                j++;
            }
            else dekwyraz += wyrazy[i][j];

        }
    }
}



int main()
{
    string dzialanie;
    cin >> dzialanie;

    for(int i = 0; i < 1000; i++)
    {
        cin >> wyrazy[i];
    }
    if (dzialanie == "KOMPRESJA")
    {
        cout << kompresja();
    }
    else if (dzialanie == "DEKOMPRESJA")
    {
        cout << dekompresja();
    }

}
