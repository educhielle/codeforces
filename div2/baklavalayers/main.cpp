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
    int t;
    cin >> t;
    while (t--)
    {
        int l, n;
        cin >> l >> n;
        cout << (n*((l<<1)+n-1)>>1) << '\n';
    }
}
