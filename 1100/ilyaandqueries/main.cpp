#include <iostream>
#include <string>
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
    string s;
    cin >> s;
    vector<int> v{0};
    int m, max_idx = 0;
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        for (; max_idx < r; max_idx++)
            v.push_back(v[max_idx]+(s[max_idx]==s[max_idx+1]));
        cout << (v[r-1] - v[l-1]) << '\n';
    }
}
