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
    int n, m, idx, max=0;
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        int a, t;
        cin >> a;
        t = (a / m) + (a % m != 0);
        if (t >= max)
        {
            idx = i;
            max = t;
        }
    }
    cout << idx << '\n';
}