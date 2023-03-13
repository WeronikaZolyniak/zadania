#include <bits/stdc++.h>

using namespace std;

char litery[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','w','x','y','z'};

int main()
{
    string napis;
    getline(cin, napis);

    for(int litera = 0; litera < 26; litera++)
    {
        int liczba = 0;
        for(int i = 0; i < napis.length(); i++)
        {
            if (litery[litera] == napis[i]) liczba++;
        }
        if (liczba != 0) cout << litery[litera] << ": " << liczba << endl;
    }
}
