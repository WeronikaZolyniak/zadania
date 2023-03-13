#include <iostream>
#include <cstdio>
using namespace std;

long sumacyfr(long liczba)
{
    if (liczba < 10) return liczba;
    else return liczba % 10 + sumacyfr(liczba /10);
}

int main()
{
    long liczba;
    cin >> liczba;

    cout << sumacyfr(liczba);
}
