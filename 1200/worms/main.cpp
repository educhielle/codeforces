#include <iostream>
#include <vector>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int find_pile(int q, const vector<int> & a, int begin, int end)
{
    int i = begin + end;
    i = (i >> 1) + (i & 1);
    if (q <= a[i-1]) return find_pile(q, a, begin, i);
    if (q > a[i]) return find_pile(q, a, i, end);
    return i;
}

int main()
{
    fastIO();
    int n; // number of piles
    cin >> n;
    vector<int> a(n+1);
    a[0] = 0;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
    int m; // number of juice worms
    cin >> m;
    while (m--)
    {
        int q;
        cin >> q;
        cout << find_pile(q, a, 0, n) << '\n';
    }
}
