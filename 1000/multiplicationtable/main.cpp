#include <iostream>

using namespace std;

int main()
{
    int n, x, t=0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int q = x / i;
        int r = x % i;
        if (!r && q <= n) t++;
    }
    cout << t << '\n';
}
