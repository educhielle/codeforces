#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;

    if (n < 0)
    {
        n = -n;
        int64_t d0 = n % 10;
        n /= 10;
        int64_t d1 = n % 10;
        int64_t dr = min(d0, d1);
        n = -(n + dr - d1);
    }
    cout << n << '\n';
}
