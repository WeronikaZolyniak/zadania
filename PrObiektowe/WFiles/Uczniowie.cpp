#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

struct uczen {
int nr;
string imie;
string nazwisko;
int poziom;
char oddzial;
void drukuj()
    {
    cout<< nr<< ": "<< nazwisko << " " << imie << " klasa " << poziom <<oddzial <<endl;

    }
};

vector <uczen> uczniowie;

string toLowerCase(string s)
{
    for(int i = 0; i < s.size(); i++) s[i] += 32;
    return s;
}

void SprawdzNazwisko()
{
    cout << "Podaj Nazwisko: ";
    string nazwisko;
    cin >> nazwisko;
    for(uczen u: uczniowie)
    {
        if(toLowerCase(u.nazwisko) == nazwisko) u.drukuj();
    }
}

bool Porownaj(uczen u1, uczen u2)
{
    if(u1.nazwisko == u2.nazwisko) return u1.imie < u2.imie;
    else return u1.nazwisko < u2.nazwisko;
}

int main() {
ifstream plik("szablony_uczniowie.txt");
for (int i=0; i<225; i++)
    {
    uczen u;
    plik >>u.nr >> u.nazwisko >> u.imie >> u.poziom >> u.oddzial;
    uczniowie.push_back(u);
    }
//for (uczen u; uczniowie){
//    u.drukuj();
//}

SprawdzNazwisko();
sort(uczniowie.begin(), uczniowie.end());
return 0;
}
