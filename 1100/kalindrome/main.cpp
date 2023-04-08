#include <iostream>
#include <vector>

using namespace std;

bool isKalindrome(vector<int> & v, int ignore)
{
    int p0 = 0, p1 = v.size()-1;
    while (p0 < p1)
    {
        while (v[p0] == ignore) p0++;
        while (v[p1] == ignore) p1--;
        if ( v[p0] != v[p1] )
        {
            if (!ignore) return isKalindrome(v, v[p0]) || isKalindrome(v, v[p1]);
            else return false;
        }
        p0++;
        p1--;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto & e : v) cin >> e;
        cout << ( isKalindrome(v, 0) ? "YES" : "NO" ) << '\n';
    }
}
