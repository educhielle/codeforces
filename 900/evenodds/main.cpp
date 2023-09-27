#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    uint64_t n, k;
    cin >> n >> k;
    uint64_t h = (n>>1) + (n&1);
    cout << ( k <= h ? (k<<1)-1 : (k-h)<<1 ) << '\n';
}
