#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    int tab[4];

    cin >> N;

    for(int i = 0; i < N; i++) cin >> tab[i];

    int max = tab[0];
    for(int i = 0; i < N; i++) {
        if(tab[i] > max) max = tab[i];
    }

 int min = tab[0];
 for(int i = 0; i < N; i++) {
    if(tab[i] > max) max = tab[i];
 }
cout << max << endl;
cout << max << endl;
 return 0;
}
