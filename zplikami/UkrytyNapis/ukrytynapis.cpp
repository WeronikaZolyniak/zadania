#include <bits/stdc++.h>
#include <string>

using namespace std;


char literka(long l)
{
    if (l < 10) return (char)('0' + l);
    return (char)('A' - 10 + l);
}

string ToString(long l)
{
    string napis;
    while(liczba > 0)
    {
        napis = literka()
    }

}

int main()
{
    ifstream plik;
    plik.open("ukryty_napis.txt");
    long l;
    while(plik >> l)
    {
        cout << l << " ";
    }
}
