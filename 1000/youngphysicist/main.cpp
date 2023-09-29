#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z;
    x = y = z = 0;
    cin >> n;
    while (n--)
    {
        int xi, yi, zi;
        cin >> xi >> yi >> zi;
        x += xi;
        y += yi;
        z += zi;
    }
    cout << (x || y || z ? "NO\n" : "YES\n");
}
