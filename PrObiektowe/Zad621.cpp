#include <iostream>
#include <cmath>

using namespace std;

template <class T> class Macierz
{
    private:
        T w1;
        T w2;
        T w3;
        T w4;
    public:
        Macierz(T _w1,T _w2,T _w3,T _w4)
        {
            w1 = _w1;
            w2 = _w2;
            w3 = _w3;
            w4 = _w4;
        }
        void print()
        {
            std::cout << w1 << " " << w2 << std::endl << w3 << " " << w4 << std::endl;
        }
        void Setw1(T _w1)
        {
            w1 = _w1;
        }
        void Setw2(T _w2)
        {
            w2 = _w2;
        }
        void Setw3(T _w3)
        {
            w3 = _w3;
        }
        void Setw4(T _w4)
        {
            w4 = _w4;
        }
        T Wyznacznik()
        {
            return w1 * w3 - w2 * w4;
        }



};

int main()
{
    Macierz<std::string> m("kot","ala","miec","rower");
    m.print();
}
