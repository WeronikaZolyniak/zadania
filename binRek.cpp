#include <iostream>
#include <cstdio>
using namespace std;

void binarna(int liczba)
{
    if (liczba == 1) cout << 1;
    else
    {
        binarna(liczba / 2);
        cout << liczba % 2;
    }
}

int main()
{
    int liczba;
    cin >> liczba;
    binarna(liczba);

}
