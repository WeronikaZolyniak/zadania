#include <iostream>
using namespace std;

struct zestaw
{
        int stopien;
        long double *wspolczynniki;
        int ilosczap;
        long double *argumenty;

};

long double horner(long double tab[], int size, long double x)
{
    long double y = tab[0];
    for(int i = 1; i < size; i++)
    {
        y = y*x + tab[i];
    }
    return y;
}

int main()
{
    int ilosczest;
    zestaw zestawy[ilosczest];

    cin >> ilosczest;
    for(int i = 0; i < ilosczest; i++)
    {
        cin >> zestawy[i].stopien;
        zestawy[i].wspolczynniki = new long double[zestawy[i].stopien + 1];
        for (int j = 0; j < zestawy[i].stopien + 1; j++)
        {
            cin >> zestawy[i].wspolczynniki[j];
        }
        cin >> zestawy[i].ilosczap;
        zestawy[i].argumenty = new long double[zestawy[i].ilosczap];
        for (int j = 0; j < zestawy[i].ilosczap; j++)
        {
            cin >> zestawy[i].argumenty[j];
        }
    }

    for(int i = 0; i < ilosczest; i++)
    {
        for (int j = 0; j < zestawy[i].ilosczap; j++)
       {
           cout << horner(zestawy[i].wspolczynniki, zestawy[i].stopien, zestawy[i].argumenty[j]) << endl;
       }

   }

   for(int i = 0; i < ilosczest; i++)
    {
        delete [] zestawy[i].argumenty;
        delete [] zestawy[i].wspolczynniki;
   }


}
