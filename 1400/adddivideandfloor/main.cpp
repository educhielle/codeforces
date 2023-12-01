#include <iostream>
#include <bit>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned t;
    cin >> t;
    while (t--)
    {
        unsigned n;
        cin >> n;
        unsigned h=0, l=1000000000;
        for (unsigned t, c=n; c--;)
        {
            cin >> t;
            if (t > h) h = t;
            if (t < l) l = t;
        }
        unsigned r, d=h-l;
        if (d) for (r=1;d>>=1;r++);
        else r=0;
        cout << r << '\n';
        if (r && r <= n) while (l!=h)
        {
            int b = (l && has_single_bit(l+1)) || ((l&1) && !has_single_bit(h+1));
            l = (l+b) >> 1;
            h = (h+b) >> 1;
            cout << b << ' ';
        }
        cout << '\n';
    }
}
