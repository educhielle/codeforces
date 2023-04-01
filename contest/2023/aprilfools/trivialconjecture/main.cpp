#include <iostream>

using namespace std;

int f(int n)
{
    if (n & 1) return 3*n+1;
    return n/2;
}

int main()
{
    int k;
    std::cin >> k;
    int n = 5;
    while (--k)
    {
        // std::cout << n << '\n';
        if ( (n-1) % 3 || (n-1)/3 <= 1 ) n <<= 1;
        else { n = (n-1) / 3; k--; }
    }
    std::cout << n << '\n';
    // std::cout << '\n';
    // while (n != 1)
    // {
    //     n = f(n);
    //     cout << n << ' ';
    // }
    // cout << '\n';
}
