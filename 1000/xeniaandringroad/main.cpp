#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    uint64_t n, m, i, pos=0, dist=0;
    cin >> n >> m;
    while (m--)
    {
        cin >> i;
        dist += (--i<pos?n:0) + i - pos;
        pos = i;
    }
    cout << dist << '\n';
}
