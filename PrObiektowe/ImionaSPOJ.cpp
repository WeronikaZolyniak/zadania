#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string DuzLit(string napis)
{
    string naDuze;
    for(int i = 0; i < napis.length(); i++)
    {
        if(napis[i] > 95) naDuze += napis[i] - 32;
        else naDuze += napis[i];
    }
    return naDuze;
}

bool sortuj(pair<string,int> p1 , pair<string,int> p2)
{
    if(p1.second != p2.second) return p1.second > p2.second;
    else return p1.first < p2.first;
}

int main()
{
    map<string,int> mapa;
    string nr;
    string nazwisko;
    string imie;
    while(cin >> nr >> nazwisko >> imie)
    {
        imie = DuzLit(imie);
        ++mapa[imie];
    }

    vector<pair <string, int>> v;

    for(pair <string, int> p : mapa)
    {
        v.push_back(p);
    }

    sort(v.begin(),v.end(), sortuj);

    for(pair <string, int> p : v)
    {
        cout << p.first << " " << p.second << endl;
    }
}
