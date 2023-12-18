#include <iostream>
#include <vector>

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
    vector<int> vab, vba;
    for (int c1=' ', c0, i=0; (c0 = getchar()) != '\n'; i++)
    {
        if (c1 == 'A' && c0 == 'B') vab.push_back(i);
        else if (c1 == 'B' && c0 == 'A') vba.push_back(i);
        if ( (vab.size() + vba.size() > 3) && !vab.empty() && !vba.empty() ) { cout << "YES\n"; return 0; }
        c1 = c0;
    }
    for (auto i : vab) for (auto j : vba) if ( abs(i-j) > 1 ) { cout << "YES\n"; return 0; }
    cout << "NO\n";
}
