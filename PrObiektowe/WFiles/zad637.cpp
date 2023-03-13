#include <bits/stdc++.h>

using namespace std;


struct Galeria
{
    string kodkraju;
    string miasto;
    int wymiarylok[70][2];
};
Galeria galerie[50];

void A()
{
    map <string,int> mapa;
    for(Galeria g: galerie)
    {
        mapa[g.kodkraju]++;
    }
    cout << "A" << endl;
    for(pair <string, int> p : mapa)
    {
        cout << p.first << " " << p.second << endl;
    }
    cout << endl << endl << endl;
}

void B()
{
    cout << "B: " << endl;
    Galeria g = galerie[0];
    int il = 0;
    int pow = 0;
    int najw = 0;
    int najmn = INT_MAX;
    string najwm;
    string najmnm;


    for(int i = 0;i < 50; i++)
    {
       g = galerie[i];
       il = 0;
       pow = 0;
       for(int j = 0; j < 70; j++)
       {
           if(g.wymiarylok[j][0] != 0 && g.wymiarylok[j][1] != 0)
           {
                il++;
                pow += g.wymiarylok[j][0] * g.wymiarylok[j][1];
           }
       }

       if(pow > najw)
       {
            najw = pow;
            najwm = g.miasto;
       }
       if(pow < najmn)
       {
            najmn = pow;
            najmnm = g.miasto;
       }
       cout << g.miasto << " " << pow << " " << il << endl;
    }
    cout << "Najwieksza: " << najw << " " << najwm << endl;
    cout << "Najmniejsza: " << najmn << " " << najmnm << endl << endl << endl;
}

void C()
{

}

int main()
{
    ifstream plik("galerie.txt");

    for(int i = 0; i < 50; i++)
    {
        plik >> galerie[i].kodkraju >> galerie[i].miasto;
        for(int j = 0; j < 70; j++)
        {
            plik >> galerie[i].wymiarylok[j][0] >> galerie[i].wymiarylok[j][1];
        }

    }



    A();
    B();
}
