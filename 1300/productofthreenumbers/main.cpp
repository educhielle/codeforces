#include <cmath>
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
    int t, n;
    for (cin >> t >> n; t--; cin >> n)
    {
        int limit = sqrt(n);
        vector<int> f;
        for (int i=2; i<=limit; i++)
        {
            if (n % i == 0)
            {
                n /= i;
                f.push_back(i);
                if (f.size() == 2 || n <= 1) break;
            }
        }
        if (f.size() == 2 && n != f[0] && n != f[1]) cout << "YES\n" << f[0] << ' ' << f[1] << ' ' << n << '\n';
        else cout << "NO\n";
    }
}
