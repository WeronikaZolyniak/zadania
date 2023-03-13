#include <iostream>
#include <cstdio>
using namespace std;

int silnia(int liczba)
{
    if(liczba == 1) return 1;
    else return liczba * silnia(liczba - 1);
}

float dwumian(int n, int k)
{
    if(n - k == 0 || k == 0) return -1;
    return silnia(n) / (silnia(k) * silnia(n - k));
}

int main()
{
    int n;
    int k;
    cin >> n >> k;

    cout << dwumian(n,k);


}
