#include <bits/stdc++.h>
#include <string>

using namespace std;

struct Pracownik
{
    string imie;
    string nazwisko;
    string pesel;
    double wyplata[12];
};

double srPracownikow[200];
Pracownik pracownicy[200];

double SrWynagrodzenie(double wyplata[], int index)
{
    double srednia = 0;
    for(int i = 0; i < 12; i++)
    {
        srednia += wyplata[i];
    }
    srednia = srednia / 12;
    srPracownikow[index] = srednia;
    return srednia;
}

double srednia()
{
    double srednia = 0;
    for(int i = 0; i < 200; i++)
    {
        srednia += srPracownikow[i];
    }
    srednia = srednia / 200;
    return srednia;
}

void drukuj()
{
    for(int i = 0; i < 200; i++)
    {
        cout << "imie: " << pracownicy[i].imie << "   ";
        cout << "nazwisko: " << pracownicy[i].nazwisko << "   ";
        cout <<"pesel: " << pracownicy[i].pesel << "   ";
        cout << "srednia wynagrodzenia: " << SrWynagrodzenie(pracownicy[i].wyplata, i) << endl;
    }
}

void maximum()
{
    double najwieksza = 0;
    int index;
    for(int i = 0; i < 200; i++)
    {
        if(najwieksza < srPracownikow[i])
        {
            najwieksza = srPracownikow[i];
            index = i;
        }
    }
    cout << endl << endl << endl << "Najlepiej zarabiajacy pracownik: " << endl;
    cout << "imie: " << pracownicy[index].imie << "   ";
    cout << "nazwisko: " << pracownicy[index].nazwisko << "   ";
    cout <<"pesel: " << pracownicy[index].pesel << "   ";
    cout << "srednia wynagrodzenia: " << srPracownikow[index] << endl;
}

int main()
{

    ifstream plik("pracownicy.txt");

    for(int i = 0; i < 200; i++)
    {
       plik >> pracownicy[i].nazwisko;
       plik >> pracownicy[i].imie;
       plik >> pracownicy[i].pesel;
       for(int p = 0; p < 12; p++)
       {
            plik >> pracownicy[i].wyplata[p];
       }
    }

    drukuj();
    cout << endl << endl << endl << "srednia wynagrodzenia w firmie: " << srednia() << endl;
    maximum();

}
