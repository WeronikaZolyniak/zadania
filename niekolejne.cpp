#include <iostream>
#include <math.h>
using namespace std;



int main()
{
    int n;
    cin >> n;

    int tablica[1000000];

    for (int i = 0; i < n; i++)
    {
        tablica[i] = i;
    }

    cout << tablica;

    return 0;
}
