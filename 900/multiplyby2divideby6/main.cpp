#include <bit>
#include <iostream>
    
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
    int t;
    cin >> t;
    while (t--)
    {
        unsigned n = 0;
        cin >> n;
        int b = countr_zero(n), c;
        n >>= b;
        for (c = 0; n % 3 == 0; c++) n /= 3;
        if (n != 1) c = -1;
        cout << (c >= b ? c+(c-b) : -1) << '\n';
    }
}