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
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (n >= 2021 * (n % 2020) ? "YES" : "NO") << '\n';
    }
}
