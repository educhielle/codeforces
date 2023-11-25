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
    int t;
    cin >> t;
    while (t--)
    {
        int n, b;
        cin >> n >> b >> b;
        while (n--) cout << char('a'+(n % b));
        cout << '\n';
    }
}
