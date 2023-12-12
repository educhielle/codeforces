#include <iostream>
#include <string>

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
    int score[] = {0,1};
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    while (--n)
    {
        string u;
        cin >> u;
        score[s == u]++;
        if (s != u) t = u;
    }
    cout << (score[0] > score[1] ? t : s) << '\n';
}
