#include <iostream>
#include <cstdio>
using namespace std;

double euro = 4.58;
double dolar = 3.97;

int main()
{
    cout << "Wpisz watosc w zlotowkach: \n";
    double zloty;
    cin >> zloty;
    cout << "Kwota w Dolarach: " << zloty / dolar << "\n";
    cout << "Kwota w Euro: " << zloty / euro;
    return 0;
}
