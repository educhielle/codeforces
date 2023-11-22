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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (b < a) swap(a,b);
    if (c < a) swap(a,c);
    if (c < b) swap(b,c);
    int max = 0;
    for (int x = n/a; x >= 0; x--)
    {
        int y = (n - x*a) / b;
        int z = (n - x*a - y*b) / c;
        if (x + y + z <= max) break;
        for (; y >= 0; y--)
        {
            z = (n - x*a - y*b) / c;
            if (n == x*a + y*b + z*c && x+y+z > max)
            {
                max = x+y+z;
                break;
            }
        }
    }
    cout << max << '\n';
}
