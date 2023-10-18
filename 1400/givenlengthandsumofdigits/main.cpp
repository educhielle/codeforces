#include <iostream>
#include <vector>

using namespace std;

inline void print(const vector<char> & v, char end)
{
    for (const auto c : v) cout << c;
    cout << end;
}

inline vector<char> find_small(int m, int s)
{
    if ((!s && m != 1) || (9*m < s)) return vector<char>{'-', '1'};
    if (!s) return vector<char>{'0'};
    vector<char> v(m,'0');
    s--;
    for (int i=v.size()-1; s > 0 && i > 0; s -= 9) v[i--] = s >= 9 ? '9' : (s+'0');
    v[0] = (s > 0 ? s : 0)+'1';
    return v;
}

inline vector<char> find_large(int m, int s)
{
    if ( (!s && m != 1) || (9*m < s)) return vector<char>{'-', '1'};
    vector<char> v(m,'0');
    for (int i=0; s > 0 && i < m; s -= 9) v[i++] = s >= 9 ? '9' : (s+'0');
    return v;
}

int main()
{
    int m, s;
    cin >> m >> s;
    print(find_small(m, s), ' ');
    print(find_large(m, s), '\n');
}
