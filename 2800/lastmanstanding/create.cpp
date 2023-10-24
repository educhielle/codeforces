#include <iostream>

using namespace std;

inline int number() { return rand() % 200000; }

int main()
{
    int t = 10;
    cout << t << '\n';
    while (t--)
    {
        auto n = number();
        cout << n << '\n';
        for (int i=0; i<n; i++) cout << number() << ' ';
        cout << '\n';
        for (int i=0; i<n; i++) cout << number() << ' ';
        cout << '\n';
    }
}