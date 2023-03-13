#include <bits/stdc++.h>
#include <string>
#include <cmath>

using namespace std;

float A(int n)
{
    if(n == 1) return 4.5f;
    else if (n > 1){
        return 5 * A(n - 1) + 3;
    }
    return 0.f;
}

int main()
{
    int n;
    cout << "Podaj n: ";
    cin >> n;
    cout << "Wartosc a odpowiadajaca " << n << " to: " << A(n) << endl;
}
