#include <iostream>

using namespace std;

int main()
{
    uint64_t n, m, a;
    cin >> n >> m >> a;
    uint64_t x = n / a + uint64_t(n % a != 0);
    uint64_t y = m / a + uint64_t(m % a != 0);
    cout << (x*y) << '\n';
}
