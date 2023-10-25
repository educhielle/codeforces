#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

inline vector<int> read(int n)
{
    vector<int> v(n);
    for (int i=0; i<n; cin >> v[i++]);
    return v;
}

int main()
{
    fastIO();
    int n, m;
    cin >> n;
    auto a = read(n);
    cin >> m;
    auto b = read(m);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int nPairs = 0;
    for (int i=0, j=0; i<n && j<m;)
    {
        auto diff = a[i] - b[j];
        if (abs(diff) <= 1)
        {
            nPairs++;
            i++;
            j++;
        }
        else if (diff < -1) i++;
        else j++;
    }
    cout << nPairs << '\n';
}
