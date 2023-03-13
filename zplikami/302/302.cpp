#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<pair<int,int>> punkty;

void A()
{
    int w = 0;
    int b = 0;
    int r2;
    for(pair<int,int> p: punkty)
    {
        r2 = (p.first - 200)*(p.first - 200) + (p.second - 200)*(p.second - 200);
        if(r2 == 40000) b++;
        else if(r2< 40000) w++;
    }
    cout << "A: " << w << "   " << b << endl;
}

void obliczPi(int nk, int n)
{
    double pi = 4.0 * (double)nk/(double)n;
    cout << pi << endl;
}

void B()
{
    cout << "B: " << endl;
    int n = 0;
    int r2;
    int linia = 1;
    for(pair<int,int> p: punkty)
    {
        r2 = (p.first - 200)*(p.first - 200) + (p.second - 200)*(p.second - 200);
        if(r2<= 40000) n++;

        if(linia == 1000) obliczPi(n,1000);
        else if(linia == 5000) obliczPi(n, 5000);
        linia++;
    }
    obliczPi(n, 10000);
}

int main()
{
    ifstream plik("punkty.txt");
    int x,y;
    for(int i = 0; i < 10000; i++)
    {
        plik >> x >> y;
        punkty.push_back(make_pair(x,y));
    }
    A();
    B();
    //for(pair<int,int> p: punkty) cout << p.first << p.second << endl;
}
