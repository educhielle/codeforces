#include <iostream>
#include <cstdlib>

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
    for (uint64_t n; t--;)
    {
        cin >> n;
        cout << ((n-1) * n * (n+1) / 3) << '\n';
    }
}
