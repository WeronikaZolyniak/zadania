#include <bits/stdc++.h>
using namespace std;

vector<string> dane;

void A()
{
    string najdluzsze = dane[0];
    int naj = 0;
    string najkrotsze = dane[0];
    int mini = INT_MAX;
    char samogloski[6] = {'A','E','I','O','U','Y'};
    for(string slowo: dane)
    {
        int dl = 0;
        for(int i = 0; i < slowo.length(); i++)
        {
            bool spolgloska = true;
            for(int j = 0; j < 6; j++)
            {
                if(slowo[i] == samogloski[j]) spolgloska = false;

            }
            if(spolgloska) dl++;
        }
        if(dl > naj)
        {
            najdluzsze = slowo;
            naj = dl;
        }
        if(dl < mini)
        {
            najkrotsze = slowo;
            mini = dl;
        }
    }
    cout << "A: " << endl << "najdluzsze: " << najdluzsze << endl << "najkrotsze: " << najkrotsze << endl;
}

bool sortuj(pair<string, int> p1, pair<string, int> p2)
{
    if(p1.second > p2.second) return true;
    else return false;
}

void B()
{
    cout << "B: " << endl;
    map<string,int> slowa;
    for(string slowo: dane)
    {
        ++slowa[slowo];
    }

    vector<pair<string, int>> v;
    for(pair<string, int> slowo: slowa)
    {
        v.push_back(slowo);
    }
    sort(v.begin(), v.end(), sortuj);

    for(pair<string, int> p: v)
    {
        cout << p.first << " " << p.second << endl;
    }
}

int main()
{
    ifstream plik("tekst.txt");

    string slowo;
    while(plik >> slowo) dane.push_back(slowo);
    A();
    B();

}
