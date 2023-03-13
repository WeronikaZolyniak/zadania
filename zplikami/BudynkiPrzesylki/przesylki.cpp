#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

struct budynek
{
    int numer;
    int mieszkanie[20];
};

struct przesylka
{
    int numerb;
    int numerm;
};

budynek budynki[1000];
przesylka przesylki[1000];
int indexbloku = 0;
int indexprzesylki = 0;


bool binarne(int t[],const int n,const int szukane) {
  int a = 0; int b = n-1;
  int c;
  while(a < b){
    c = (a + b)/2;
   if(t[c] == szukane) return true;
   else if(t[c] > szukane) {
      b = c-1;
    } else a = c+1;
  }
  if(t[a] == szukane) return true;
  else return false;
}

bool jestMieszkanie()
{
    bool j = false;
    for(int i = 0; i < 20; i++)
    {
        if(budynki[indexbloku].mieszkanie[i] == przesylki[indexprzesylki].numerm) j = true;
    }
    return j;
}

bool jestBlok()
{
    bool istniejeblok = false;

    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++)
        {
            if (budynki[i].numer == przesylki[j].numerb)
            {
                istniejeblok = true;
                indexbloku = i;
                indexprzesylki = j;
            }
        }
    }
    return istniejeblok;
}



int A()
{
    int zleadresy = 0;
    for(int i = 0; i < 1000; i++)
    {
        if(jestBlok())
        {
            if(jestMieszkanie() == false) zleadresy++;
        }
        else zleadresy++;
    }
    return zleadresy;
}

int main()
{
    ifstream plikA("adresy.txt");
    ifstream plikP("przesylki.txt");



    for(int i = 0; i < 1000; i++)
    {
        plikA >> budynki[i].numer;
        for(int j = 0; j < 20; j++) plikA >> budynki[i].mieszkanie[j];

        plikP >> przesylki[i].numerb;
        plikP >> przesylki[i].numerm;
    }



    cout << "Ilosc adresow ktore nie istnieja: " << A() << endl;
}

