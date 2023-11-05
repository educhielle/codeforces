#include <iostream>
#include <unordered_map>
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
    int n, m, count = 0;
    cin >> n >> m;
    vector<int> a(n+1), l(n+1);
    for (int i=1; i<=n; i++) cin >> a[i];
    unordered_map<int,bool> map;
    for (int i=n; i; i--)
    {
        auto & x = a[i];
        if (!map[x]) count++;
        map[x] = true;
        l[i] = count;
    }
    while (m--)
    {
        int i;
        cin >> i;
        cout << l[i] << '\n';
    }
}
