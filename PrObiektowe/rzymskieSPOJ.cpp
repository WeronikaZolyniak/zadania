#include <iostream>
#include <map>
#include <cmath>

using namespace std;

struct ParaRzym
{
    string s1;
    string s2;

    ParaRzym(string r1, string r2)
    {
        s1 = r1;
        s2 = r2;
    }

    int wartosc(char z)
    {
        switch(z)
        {
            case 'M' :return 1000;
            case 'D' :return 500;
            case 'C' :return 100;
            case 'L' :return 50;
            case 'X' :return 10;
            case 'V' :return 5;
            case 'I' :return 1;
            default :return 0;
        }
    }

    int naDziesiatkowe(string s)
    {
        int d = 0;
        for(int i = 0; i < s.length() - 1; i+= 2)
        {
            auto n = wartosc(s[i]);
            if(i < s.size()-1 && wartosc(s[i+1]) > n) d-= n;
            else d += n;
        }
        return d;
    }



    string naRzym(int l)
    {
        string rz;
        string znaki[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int wartosci[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        for(int i = 0; i < 13; i++)
        {
            while(l >= wartosci[i])
            {
                rz += znaki[i];
                l -= wartosci[i];
            }
        }
        return rz;
    }

    string dodaj()
    {
        int l = naDziesiatkowe(s1) + naDziesiatkowe(s2);
        return naRzym(l);
    }

};

int main()
{
    string rz1, rz2;
    while(cin >> rz1 >> rz2)
    {
        ParaRzym para(rz1,rz2);
        cout << para.dodaj() << endl;
    }



    //cout << rzym.naDziesiatkowe() << endl;
    //Rzymskie rzym2(rzym.d);
    //cout << rzym2.Narzymskie() << "==" << rz << endl;
}
