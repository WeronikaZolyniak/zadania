#include <iostream>
#include <ctime>
#include <cstdlib>

int podziel_tablice(int*, int, int);
int wybierz_punkt_podzialu(int*, int, int);
void zamien(int*, int, int);

void sortuj(int *tab, int l, int r)
{
    if(l >= r) return;
    if(r - l == 1) {
        if(tab[r] < tab[l]) zamien(tab, l, r);
        return;
    }
    int i = podziel_tablice(tab, l, r);
    sortuj(tab, l, i - 1);
    sortuj(tab, i + 1, r);
}

int podziel_tablice(int *tab, int l, int r)
{
    int podzial = wybierz_punkt_podzialu(tab, l, r);
    int wartosc = tab[podzial];
    zamien(tab, podzial, r);
    int aktualnie = l;
    for(int i = l; i < r; i++)
    {
        if(tab[i] < wartosc)
        {
            zamien(tab, i, aktualnie);
            aktualnie++;
        }
    }
    zamien(tab, aktualnie, r);
    return aktualnie;
}

int wybierz_punkt_podzialu(int* tab, int l, int r)
{
    return (l+r)/2;
}

void zamien(int* tab, int a, int b)
{
    int c = tab[a];
    tab[a] = tab[b];
    tab[b] = c;
}

void sortowanie_babelkowe(int tab[],int n)
{
	for(int i=0;i<n;i++)
	{
        for(int j=1;j<n-i;j++)
        {
            if(tab[j-1]>tab[j])
            swap(tab[j-1], tab[j]);
        }

	}

}

int main()
{
    const int maks = 100;
    std::srand(std::time(NULL));
    int rozmiar = 100000;
    std::cout << "Rozmiar tablicy: " << rozmiar << "\n";
    int* tab = new int[rozmiar];
    for(int i = 0; i < rozmiar; i++) tab[i] = std::rand() % 1000;
    sortuj(tab, 0, rozmiar - 1);
    for(int i = 0; i < rozmiar; i++) std::cout << tab[i] << "\t";
    std::cout << std::endl;

}
