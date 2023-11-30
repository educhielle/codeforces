#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    uint64_t n, m, h, l, t;
    cin >> n >> m;
    h = n - m + 1;
    h = (h * (h-1)) >> 1;
    l = n / m;
    t = n % m;
    l = ((m-t) * (l * (l-1)) + t * (l * (l+1))) >> 1;
    cout << l << ' ' << h << '\n';
}
