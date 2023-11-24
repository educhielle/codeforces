#include <iostream>

using namespace std;

int main()
{
    char c1 = '0', c0 = '0';
    for(char c; (c = getchar()) >= '0'; c0 = c) c1 = c0;
    c0 -= c1 & 1 ? '2' : '0';
    c0 &= 3;
    cout << (!c0 ? 4 : 0) << '\n';
}