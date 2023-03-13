#include <bits/stdc++.h>
using namespace std;

vector<string> dane;

void A()
{
    int ilosc = 0;
    for(string s: dane)
    {
        int bMaCyfre = false;
        int bMaMala = false;
        int bMaDuza = false;
        for(int i = 0; i < s.length(); i++)
        {
            if(int(s[i]) >= 48 && int(s[i]) <= 57) bMaCyfre = true;
            if(int(s[i]) >= 66 && int(s[i]) <= 90) bMaDuza = true;
            if (int(s[i]) >= 97 && int(s[i]) <= 122) bMaMala = true;
        }
        if(bMaCyfre && bMaMala && bMaDuza) ilosc++;
    }

    cout << "A: " << ilosc << endl;
}

int kodASCII(string slowo)
{
    int kod = 0;
    for(int i = 0; i < slowo.length(); i++)
    {
        kod += int(slowo[i]);
    }
    return kod;
}

bool sortuj(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.second > p2.second) return true;
    else return false;
}

void B()
{
    map<int,int> mapa;
    for(string s: dane)
    {
        ++mapa[kodASCII(s)];
    }
    vector<pair<int,int>> v;
    for(pair<int,int> para: mapa)
    {
        v.push_back(para);
    }

    sort(v.begin(), v.end(), sortuj);

    cout << "B: " << endl;
    for(pair<int,int> para: v)
    {
        cout << para.first << "  " << para.second << endl;
    }

}

int main()
{
    ifstream plik;
    plik.open("hasla.txt");

    for(int i = 0; i < 200; i++)
    {
        string slowo;
        plik >> slowo;
        dane.push_back(slowo);
    }

    A();
    B();
}
