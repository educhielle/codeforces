#include <iostream>

using namespace std;

int main()
{
    int n, ndays=0;
    cin >> n;
    do ndays += n & 1;
    while (n >>= 1);
    cout << ndays << '\n';
}
