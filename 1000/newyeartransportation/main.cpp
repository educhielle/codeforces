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
    int n, t, a, s=1;
    bool f = false;
    cin >> n >> t;
    for (int i=1; i<=n; i++)
    {
        if (s >= t)
        {
            f = s == t;
            break;
        }
        int a;
        cin >> a;
        if (i < s) continue;
        s += a;
    }
    cout << (f ? "YES\n" : "NO\n");
}
