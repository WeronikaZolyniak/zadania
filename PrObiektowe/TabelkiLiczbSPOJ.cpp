#include <iostream>
#include <cmath>

using namespace std;

struct Tabela
{
        int szer;
        int wys;
        int ** tablica;
        Tabela( int wysokosc, int szerokosc)
        {
            szer = szerokosc;
            wys = wysokosc;
            tablica = new int *[wys];
            for(int i = 0; i < wys; i++) tablica[i] = new int [szer];
        }
        void print()
        {
            for(int i = 0; i < wys; i++)
            {
                for(int j = 0; j < szer; j++) cout << tablica[i][j] << " ";
                cout << endl;

            }
            cout << endl << endl;
        }

        void zamien()
        {
            int pierwszy = tablica[0][0];

            //pierwsza linia
            for(int j = 1; j < szer; j++)
            {
                tablica[0][j-1] = tablica[0][j];
            }
            //pionowa tylnia linia
            for(int j = 0; j < wys - 1; j++)
            {
                tablica[j][szer - 1] = tablica[j+1][szer - 1];
            }

            //dolna linia
            for(int j = szer - 1; j > 0; j--)
            {
                tablica[wys - 1][j] = tablica[wys - 1][j - 1];
            }

            //pionowa przednia linia
            for(int j = wys - 1; j > 1; j--)
            {
                tablica[j][0] = tablica[j-1][0];
            }

            tablica[1][0] = pierwszy;
        }

        ~Tabela()
        {
            for(int i = 0; i < wys; i++) delete [] tablica[i];
            delete [] tablica;
        }
};

int main()
{
    int liczba;
    cin >> liczba;
    for(int i = 0; i < liczba; i++)
    {
        int wysok;
        int szero;
        cin >> wysok >> szero;
        Tabela t(wysok,szero);
        for(int i = 0; i < wysok; i++)
        {
            for(int j = 0; j < szero; j++) cin >> t.tablica[i][j];

        }

        t.zamien();
        t.print();
    }


}
