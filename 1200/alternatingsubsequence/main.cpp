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
    int t, n;
    for (cin >> t; t--;)
    {
        long long prev = 0, curr, sum = 0;
        for (cin >> n; n--;)
        {
            cin >> curr;
            if ((prev < 0 && curr < 0) || (prev > 0 && curr > 0))
            {
                if (curr > prev)
                {
                    sum += curr - prev;
                    prev = curr;
                }
            }
            else
            {
                sum += curr;
                prev = curr;
            }
        }
        cout << sum << '\n';
    }
}
