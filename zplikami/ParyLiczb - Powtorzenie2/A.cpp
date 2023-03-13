#include <bits/stdc++.h>
#include <string>

using namespace std;

int NWD(int a, int b)
{
    while(a!=b)
    {
        if(a>b) a-=b;
        else b-=a;
    }

    return a;
}

int A(int tab[])
{
    int linijkiparzyste = 0;
    int i = 0;
    while (i < 2000)
    {
        if(tab[i] % 2 == 0 && tab[i + 1] % 2 == 0) linijkiparzyste++;
        i = i+2;
    }
    return linijkiparzyste;
}

int B(int tab[])
{
    int pierwszawieksza = 0;
    int i = 0;
    while (i < 2000)
    {
        if(tab[i] > tab[i + 1]) pierwszawieksza++;
        i = i+2;
    }
    return pierwszawieksza;
}

int C(int tab[])
{
    int wielokrotnosci = 0;
    int i = 0;
    while (i < 2000)
    {
        if(tab[i] % tab[i + 1] == 0 || tab[i + 1] % tab[i] == 0) wielokrotnosci++;
        i = i+2;
    }
    return wielokrotnosci;
}

int D(int tab[])
{
    int wzgledniepierwsze = 0;
    int i = 0;
    while (i < 2000)
    {
        if(NWD(tab[i], tab[i + 1]) == 1) wzgledniepierwsze++;
        i = i+2;
    }
    return wzgledniepierwsze;
}

int E(int tab[])
{
    int tasamasuma = 0;
    int i = 0;
    int suma1 = 0;
    int suma2 = 0;
    while (i < 2000)
    {
        string napis1 = to_string(tab[i]);
        string napis2 = to_string(tab[i + 1]);
        suma1 = 0;
        suma2 = 0;
        for (int n = 0; n < napis1.length(); n++) {
            char znak1 = napis1[n];
            int cyfra1 = znak1 - '0';
            suma1 = suma1 + cyfra1;
        }
        for (int m = 0; m < napis2.length(); m++) {
            char znak2 = napis2[m];
            int cyfra2 = znak2 - '0';
            suma2 = suma2 + cyfra2;
        }

        if (suma1 == suma2) tasamasuma++;
        i = i + 2;
    }
    return tasamasuma;
}

void F(int tab[])
{
    ofstream plik2;
    plik2.open("POTEGI.TXT");
    int i = 0;
    while (i < 2000)
    {
        for(int n = 0; n < 10; n++)
        {
            if(pow(3,n) == tab[i]) plik2 << tab[i] << endl;
        }
        i++;
    }
    plik2.close();

}


int main()
{
    ifstream plik;
    plik.open("PARY_LICZB.TXT");

    int tab[2000];

    int n = 0;
    while(n < 2000)
    {
        plik >> tab[n] >> tab[n + 1];
        n = n+2;

    }



    cout << "linijki z dwoma parzystymi liczbami: " << A(tab) << endl;
    cout << "linijki z pierwsza liczba wieksza od drugiej: " << B(tab) << endl;
    cout << "linijki w ktorych jedna liczba jest wielokrotnoscia drugiej: " << C(tab) << endl;
    cout << "linijki w ktorych liczby sa wzglednie pierwszymi: " << D(tab) << endl;
    cout << "linijki w ktorych suma cyfr pierwszej liczby jest rowna sumie cyfr drugiej liczby: " << E(tab) << endl;
    F(tab);


}
