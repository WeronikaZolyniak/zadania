/*1. wczytaj cale zdanie
2. wypisz na ekran odwrocone zdanie
*/

#include <bits/stdc++.h>

using namespace std;


int main()
{
    string zdanie;
    getline(cin, zdanie);

    int i = zdanie.length();
    while(i >= 0)
    {
        cout << zdanie[i];
        i = i-1;
    }

    return 0;
}
