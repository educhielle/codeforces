#include <algorithm>
#include <iostream>
#include <utility>

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
    pair<int,int> v[5000];
    int n, r=0;
    cin >> n;
    for (int i=0; i<n; i++) cin >> v[i].first >> v[i].second;
    sort(v,&v[n]);
    for (int i=0; i<n; i++) r = v[i].second < r ? v[i].first : v[i].second;
    cout << r << '\n';
}
