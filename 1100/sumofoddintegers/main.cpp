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
    for (int n,k; t--; )
    {
        cin >> n >> k;
        cout << ( (n&1) == (k&1) && n/k >= k ? "YES\n" : "NO\n" );
    }
}
