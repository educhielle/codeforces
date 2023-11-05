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
    int n, t;
    cin >> n >> t;
    if (n == 1 && t == 10) cout << "-1\n";
    else
    {
        cout << t;
        if (t == 10) n--;
        while (--n) cout << '0';
        cout << '\n';
    }
}
