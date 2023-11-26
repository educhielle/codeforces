#include <iostream>
#include <string>
#include <unordered_map>

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
    unordered_map<string,string> d;
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        string s, t;
        cin >> s >> t;
        d[s] = t.size() < s.size() ? t : s;
    }
    while (n--)
    {
        string s;
        cin >> s;
        cout << d[s] << ' ';
    }
    cout << '\n';
}
