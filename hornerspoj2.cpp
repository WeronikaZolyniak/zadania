#include <iostream>
using namespace std;

long double horner(long double tab[], int sizem, long double x)
{
    long double y = tab[0];
    for(int i = 1; i < sizem; i++)
    {
        y = y*x + tab[i];
    }
    return y;
}

int main()
{
    int ilosczest;

    cin >> ilosczest;
    for(int i = 0; i < ilosczest; i++)
    {
        int stopien;
        cin >> stopien;
        long double *wspolczynniki = new long double[stopien + 1];
        for (int j = 0; j < stopien + 1; j++)
        {
            cin >> wspolczynniki[j];
        }
        int ilosczap;
        cin >> ilosczap;
        long double *argumenty = new long double[ilosczap];
        for (int j = 0; j < ilosczap; j++)
        {
            cin >> argumenty[j];
            cout << horner(wspolczynniki, stopien, argumenty[j]) << endl;
        }
        delete [] wspolczynniki;
        delete [] argumenty;
    }


}
