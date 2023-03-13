#include <bits/stdc++.h>

using namespace std;

bool bAnagram(string napis1, string napis2)
{
    if (napis1.length() != napis2.length()) return false;
    bool bJestAnagramem = true;
    for(int litera = 0; litera < napis1.length(); litera++)
    {
        for(int i = 0; i < napis2.length(); i++)
        {
            if (bJestAnagramem = true && napis1[litera] == napis2[i]) bJestAnagramem = true;
            else bJestAnagramem = false;
        }
    }
    return bJestAnagramem;
}

int main()
{
    string napis1, napis2;
    getline(cin, napis1);
    getline(cin, napis2);
    if(bAnagram(napis1, napis2)) cout << "To anagramy";
    else cout << "to nie anagramy";


}
