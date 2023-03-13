#include <bits/stdc++.h>

using namespace std;

int SprawdzLiczbeLiter(string zdanie)
{
    int liczba = 0;
    for(int i = 0; i< zdanie.size(); i++)
    {
        if (zdanie[i] == ' ' && zdanie[i+1] != ' ') liczba++;
    }
    liczba++;
    return liczba;
}

int main()
{
    string zdanie;
    getline(cin, zdanie);
    cout << SprawdzLiczbeLiter(zdanie);
    return 0;
}


