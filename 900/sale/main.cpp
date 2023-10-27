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

int main()
{
    fastIO();
    int n, m, sum = 0;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i=0; i < m && v[i] < 0; i++) sum -= v[i];
    cout << sum << '\n';
}
