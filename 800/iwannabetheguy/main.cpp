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
    int n, p;
    cin >> n;
    vector<bool> v(n+1,false);
    for (int f=0; f<2; f++)
    {
        cin >> p;
        while (p--)
        {
            int i;
            cin >> i;
            v[i] = true;
        }
    }
    bool win = true;
    for (int i=1; i<v.size(); i++)
        if (!v[i]) { win = false; break; }
    cout << ( win ? "I become the guy." : "Oh, my keyboard!" ) << '\n';
}
