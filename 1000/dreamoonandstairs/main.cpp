#include <iostream>

int main()
{
    int n, m;
    std::cin >> n >> m;
    if (m > n) { std::cout << "-1\n"; return 0; }
    n = (n >> 1) + (n & 1);
    std::cout << (n + (m - (n % m)) % m) << '\n';
}
