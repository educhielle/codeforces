#include <iostream>

using namespace std;

int main()
{
    int k, n, w;
    cin >> k >> n >> w;
    int cost = k*w*(w+1) >> 1;
    int borrow = cost - n;
    if (borrow < 0) borrow = 0;
    cout << borrow << '\n';
}
