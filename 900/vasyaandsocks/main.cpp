#include <iostream>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    int n, m, r, days = 0;
    cin >> n >> m;
    while (n >= m)
    {
        r = n % m;
        n -= r;
        days += n;
        n = n / m + r;
    }
    cout << (days+n) << '\n';
}
