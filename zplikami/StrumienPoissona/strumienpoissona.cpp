#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

vector<pair<double,int>> punkty;

const double P = 2000000.0;

long obliczPole(int n0, double lambda)
{
    int naleza = 0;
    for(pair<double,int> punkt: punkty)
    {
        int N = n0 * exp(-lambda * punkt.first);
        if(N >= punkt.second) naleza++;
    }
    return P*naleza/100000.0;
}

int main()
{
    ifstream plikp("punkty_losowe.txt");
    ifstream plikex("exponent_monte_carlo.txt");
    double x;
    int y;
    for(int i = 0; i < 100000; i++)
    {
        plikp >> x >> y;
        punkty.push_back(make_pair(x,y));
    }

    double lambda = 0.0;
    int n0 = 0;
    long suma = 0;
    long t;
    for(int i = 0; i < 100; i++)
    {
        plikex >> n0 >> lambda;

        t = obliczPole(n0, lambda);
        suma += t;

    }
    cout << "suma: " << suma << endl;
}
