#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    bool reversed = s.size() == t.size();
    auto last = t.size() - 1;
    for (int i=0; i<s.length() && reversed; i++)
        reversed &= s[i] == t[last-i];
    cout << ( reversed ? "YES" : "NO" ) << '\n';
}
