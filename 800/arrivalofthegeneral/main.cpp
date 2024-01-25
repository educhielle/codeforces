#include <iostream>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    int n, x, hx, lx, hi, li;
    cin >> n >> x;
    hx = lx = x;
    hi = li = 0;
    for (int i=1; i<n; i++)
    {
        cin >> x;
        if (x > hx)
        {
            hx = x;
            hi = i;
        }
        else if (x <= lx)
        {
            lx = x;
            li = i;
        }
    }
    cout << (hi + n - 1 - li - int(li < hi)) << '\n';
}
