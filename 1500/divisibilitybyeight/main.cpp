#include <iostream>
#include <string>
#include <vector>

using namespace std;

int get_number(const vector<int> & v, const vector<int> & idx, int n_digits)
{
    int number = 0;
    while (n_digits--) number = 10 * number + v[idx[n_digits]];
    return number;
}

int find_div(const vector<int> & v, vector<int> & idx, int ref, int start, int mask)
{
    int n_digits = ref + 1;
    int & i = idx[ref];
    for (i=start; i>=0; i--)
    {
        if (!(get_number(v, idx, n_digits) & mask)) return i;
        else for (int j=ref-1; j>=0; j--)
            if (v[i] == v[idx[j]]) return -1;
    }
    return -1;
}

int main()
{
    const int DIV2 = (1<<1)-1;
    const int DIV4 = (1<<2)-1;
    const int DIV8 = (1<<3)-1;
    string n;
    cin >> n;

    // one-digit number (0 or 8)
    for (auto c : n)
    {
        if (c == '0' || c == '8')
        {
            cout << "YES\n" << c << '\n';
            return 0;
        }
    }

    // two-digit number [16,24,...,96]
    vector<int> v;
    for (auto c : n) v.push_back( int(c-'0') );
    vector<int> idx(3, v.size());
    auto & i = idx[0];
    auto & j = idx[1];
    auto & k = idx[2];
    k = -1;
    while (true)
    {
        i = find_div(v, idx, 0, i-1, DIV2);
        if (i < 1) break;
        j = find_div(v, idx, 1, i-1, DIV8);
        if (j != -1)
        {
            cout << "YES\n" << get_number(v, idx, 2) << '\n';
            return 0;
        }
    }

    // three or more digits
    i = v.size();
    while (true)
    {
        i = find_div(v, idx, 0, i-1, DIV2);
        if (i < 2) break;
        j = find_div(v, idx, 1, i-1, DIV4);
        k = find_div(v, idx, 2, j-1, DIV8);
        if (k >= 0)
        {
            cout << "YES\n" << get_number(v, idx, 3) << '\n';
            return 0;
        }
    }

    cout << "NO\n";
}
