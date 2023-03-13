#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
using namespace std;





int main()
{
    ifstream plik;
    plik.open("godziny.txt");
    ofstream wynik;
    wynik.open("wynik.txt");
    int ilosc;
    plik >> ilosc;



    for (int i = 0; i < ilosc; i++)
    {
        string godzina;
        getline(plik,godzina);
        for(int i = 0; i< 10000; i++)
        {
            string palindromgodz;
            int o = godzina.length();
            while(o >= 0)
            {
                palindromgodz = palindromgodz + godzina[o];
                o = o-1;
            }

            if (godzina != palindromgodz)
            {
                if((int)(godzina[3] + godzina[4]) <=60)
                {
                    if ((int)godzina[4] < 9) godzina[4] = char((int)godzina[4] + 1);
                    else
                    {
                        godzina[3] = char((int)godzina[3] + 1);
                        godzina[4] = '0';
                    }
                }

            }
            else cout << palindromgodz << endl;

        }
    }
}
