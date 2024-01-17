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
    int t, a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        cout << ((b - (a % b)) % b) << '\n';
    }
}
