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
    int n, diff = 0;
    cin >> n;
    while (n--)
    {
        char d;
        cin >> d;
        if (d == '0') diff--;
        else diff++;
    }
    cout << abs(diff) << '\n';
}
