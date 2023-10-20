#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        uint64_t n, k;
        cin >> n >> k;
        cout << (n * ((k-1) / (n-1)) + ((k-1) % (n-1)) + 1) << '\n';
    }
}
