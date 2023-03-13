#include <iostream>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;


struct Kolejka
{

    int ileEl;
    int pocz = 0;
    int N = 0;
    string * kolejka = new string[ileEl];

    Kolejka()
    {
        ileEl = 10;
        for(int i = 0; i < ileEl; i++) kolejka[i] = "";

    }
    Kolejka(int iloscel)
    {
        ileEl = iloscel;
        for(int i = 0; i < ileEl; i++) kolejka[i] = "";
    }
    ~Kolejka()
    {
        delete [] kolejka;
    }

    bool dodaj(string el)
    {

        if(N < ileEl)
        {
            kolejka[N] = el;
            //pocz++;
            N++;
            return true;
        }
        else
        {
            for(int i = 0; i < ileEl; i++)
            {
                if (kolejka[i] == "")
                {
                    kolejka[i] = el;
                    N = i + 1;
                    return true;
                }
            }
        }
        return false;

    }

    bool pobierz()
    {
        if(pocz < ileEl)
        {
            cout << kolejka[pocz] << endl;
            kolejka[pocz] = "";
            pocz++;
            return true;

        }
        else
        {
            for(int i = 0; i < ileEl; i++)
            {
                if(kolejka[i] != "")
                {
                    cout << kolejka[i] << endl;
                    kolejka[i] = "";
                    pocz = i + 1;
                    return true;
                }
            }
            return false;
        }


    }

    int rozmiar()
    {
        int r = 0;
        for(int i = 0; i < ileEl; i++)
        {
            if (kolejka[i] != "") r++;
        }
        return r;
    }

    void drukuj()
    {
        for(int i = 0; i < ileEl; i++) cout << kolejka[i] << endl;
    }


};

int main()
{
    Kolejka k(3);
    k.dodaj("oko");
    k.dodaj("drzewo");
    k.dodaj("liczba");
    k.drukuj();
    cout << "//////////////" << endl << endl;
    k.pobierz();
    k.pobierz();
    cout << "//////////////" << endl << endl;
    k.drukuj();
    cout << "//////////////" << endl << endl;
    k.pobierz();
    cout << "//////////////" << endl << endl;
    k.dodaj("plac");
    k.dodaj("droga");
    k.dodaj("informatyka");
    k.drukuj();
    cout << "//////////////" << endl << endl;
    k.pobierz();
    cout << k.rozmiar() << endl;



}
