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
        n >>= 1;
        cout << ((n * (n+1) * ((n<<1)+1) << 2) / 3) << '\n';
    }
}
