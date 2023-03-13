#include <bits/stdc++.h>
using namespace std;



class Ulamek
{
    public:
    int licznik;
    int mianownik;

    void drukuj()
    {
        cout << licznik << "/" << mianownik << endl;
    }

};

int NWD(int a, int b)
{
	int pom;

  	while(b!=0)
	{
    	pom = b;
    	b = a%b;
    	a = pom;
  	}
    return a;
}


Ulamek operator+(Ulamek& u1, Ulamek& u2)
{
    Ulamek dodanie;
    int nww = u1.mianownik / NWD(u1.mianownik,u2.mianownik) * u2.mianownik;
    dodanie.mianownik = nww;
    u1.licznik = u1.licznik * (nww / u1.mianownik);
    u2.licznik = u2.licznik * (nww / u2.mianownik);
    dodanie.licznik = u1.licznik + u2.licznik;
    return dodanie;
}

Ulamek operator-(Ulamek& u1, Ulamek& u2)
{
    Ulamek dodanie;
    int nww = u1.mianownik / NWD(u1.mianownik,u2.mianownik) * u2.mianownik;
    dodanie.mianownik = nww;
    u1.licznik = u1.licznik * (nww / u1.mianownik);
    u2.licznik = u2.licznik * (nww / u2.mianownik);
    dodanie.licznik = u1.licznik - u2.licznik;
    return dodanie;
}

Ulamek operator*(Ulamek& u1, Ulamek& u2)
{
    Ulamek wynik;
    wynik.licznik = u1.licznik * u2.licznik;
    wynik.mianownik = u1.mianownik * u2.mianownik;
    int nwd = NWD(wynik.licznik, wynik.mianownik);
    wynik.licznik /= nwd;
    wynik.mianownik /= nwd;
    return wynik;
}

Ulamek operator/(Ulamek& u1, Ulamek& u2)
{
    cout << "u2: " << u2.licznik << "/" << u2.mianownik << endl;
    Ulamek wynik;
    Ulamek noweu2;
    noweu2.licznik = u2.mianownik;
    noweu2.mianownik = u2.licznik;
    cout << "u2: " << noweu2.licznik << "/" << noweu2.mianownik << endl;

    wynik.licznik = u1.licznik * noweu2.licznik;
    wynik.mianownik = u1.mianownik * noweu2.mianownik;
    int nwd = NWD(wynik.licznik, wynik.mianownik);
    wynik.licznik /= nwd;
    wynik.mianownik /= nwd;
    return wynik;
}

bool operator<(Ulamek& u1, Ulamek& u2)
{
    int nww = u1.mianownik / NWD(u1.mianownik,u2.mianownik) * u2.mianownik;
    u1.licznik = u1.licznik * (nww / u1.mianownik);
    u2.licznik = u2.licznik * (nww / u2.mianownik);

    if(u1.licznik < u2.licznik) return true;
     return false;
}

bool operator==(Ulamek& u1, Ulamek& u2)
{
    int nww = u1.mianownik / NWD(u1.mianownik,u2.mianownik) * u2.mianownik;
    u1.licznik = u1.licznik * (nww / u1.mianownik);
    u2.licznik = u2.licznik * (nww / u2.mianownik);

    if(u1.licznik == u2.licznik) return true;
    else return false;
}

vector<Ulamek> dane;
void A()
{
    Ulamek minimum = dane[0];
    for(Ulamek u: dane)
    {
        if(u == minimum && u.mianownik < minimum.mianownik) minimum = u;
        if( u < minimum) minimum = u;
        cout << "minimum: ";
        minimum.drukuj();
    }
    cout << "A:";
    minimum.drukuj();
}

Ulamek uprosc(Ulamek u)
{
    int nwd = NWD(u.licznik, u.mianownik);
    u.licznik = u.licznik / nwd;
    u.mianownik = u.mianownik / nwd;
    return u;
}

void C()
{
    long suma;
    for( Ulamek u: dane)
    {
        uprosc(u);
        suma += u.mianownik;
    }
    cout << "C: " << suma;

}



int main()
{
    ifstream plik("dane_ulamki.txt");
    for(int i = 0; i < 1000; i++)
    {
        Ulamek u;
        plik >> u.licznik >> u.mianownik;
        dane.push_back(u);
    }
    for( Ulamek u: dane) u.drukuj();
    C();

}
