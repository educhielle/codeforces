#include <iostream>
#include <vector>

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
    vector<bool> v(1100,false);
    for (int i=0; i<100; i++)
        for (int j=0, n; (n=11*i+111*j)<1100; j++) v[n] = true;
    int t, x;
    for (cin >> t >> x; t--; cin >> x) cout << (x >= 1100 || v[x] ? "YES\n" : "NO\n");
}
