#include <bits/stdc++.h>

using namespace std;

char rzymskie[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

string suma(string rz1, string rz2)
{

}

int wartosc(char znak)
{
        switch(znak)
    {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
    }
}

int naLiczby(string rz)
{
    int liczba = 0;
    int l;
    for (int i = 0; i < rz.size(); i++)
    {
        l = wartosc(rz[i]);
        if(i> rz.size() - 1)
        {
            int n = wartosc(rz[i + 1]);
            if(n>l) liczba -= 1;
        } else liczba += 1;
    }
    return liczba;
}

int main()
{
    string rz1, rz2;
    while(cin >> rz1 >> rz2);
    cout << rz1 << "+" << rz2 << "=";
    return 0;
}
