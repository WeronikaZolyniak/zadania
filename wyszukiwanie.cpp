#include <bits/stdc++.h>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;



int binarne(int t[],const int n,const int szukane) {
  int a = 0; int b = n-1;
  int c;
  while(a < b){
    c = (a + b)/2;
   if(t[c] == szukane) return t[a];
   else if(t[c] > szukane) {
      b = c-1;
    } else a = c+1;
  }
  if(t[a] == szukane) return t[a];
  else if(abs(szukane - t[a]) >= abs(szukane - t[a + 1])) return t[a+ 1];
  else if(abs(szukane - t[a]) >= abs(szukane - t[a - 1])) return t[a - 1];
  else return t[a];
}

int main()
{
    int tab[42] = {2, 3, 5, 6, 7, 9, 12, 13, 14, 15, 17, 18, 19, 23, 24, 26, 27, 28, 34, 35, 38, 42,
    43, 45, 48, 52, 53, 54, 56, 59, 61, 65, 66, 67, 70, 73, 74, 75, 77, 78, 92, 99};

    int szukana;
    cin >> szukana;

    cout << "najblizsza liczba to: " << binarne(tab, 42, szukana) << endl;
}
