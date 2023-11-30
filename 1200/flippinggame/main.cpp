#include <iostream>

using namespace std;

int main()
{
    int n, o, z, l=-1;
    n=o=z=0;
    for (int c; (c=getchar()) != '\n'; n=10*n+c-48);
    while (n--)
    {
        auto c = getchar() - 48;
        o += c;
        z -= (c << 1) - 1;
        if (z < 0) z = 0;
        else if (z > l) l = z;
        getchar();
    }
    cout << (l+o) << '\n';
}