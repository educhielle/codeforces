#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    uint64_t t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        while (!(n & 1)) n >>= 1;
        cout << (n != 1 ? "YES\n" : "NO\n");
    }
}
