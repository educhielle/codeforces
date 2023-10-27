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
    int t, n;
    for (cin >> t; cin >> n; )
    {
        for (t=3; n % t; t = (t << 1) | 1);
        cout << (n/t) << '\n';
    }
}
