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
    for (int64_t a, b; t--; )
    {
        cin >> a >> b;
        if (b == 1) { cout << "NO\n"; continue; }
        auto z = a * b;
        if (b == 2) z *= z;
        b = z-a;
        cout << "YES\n" << a << ' ' << b << ' ' << z << '\n';
    }
}
