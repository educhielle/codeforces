#include <iostream>

using namespace std;

int main()
{
    int n, m, r=0;
    cin >> n >> m;
    while (n != m)
    {
        if (m & 1) m++;
        else if (m > 2*n) m >>= 1;
        else if (2*n <= m) n <<= 1;
        else n--;
        r++;
    }
    cout << r << '\n';
}
