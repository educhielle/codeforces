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
    int v[n+1];
    v[0] = 0;
    int max_count = 0;
    for (int i=1, pos = 0, sum = 0, count = 0; i<=n; i++)
    {
        cin >> v[i];
        sum += v[i];
        count++;
        while (sum > t)
        {
            sum -= v[++pos];
            count--;
        }
        if (count > max_count) max_count = count;
    }
    cout << max_count << '\n';
}
