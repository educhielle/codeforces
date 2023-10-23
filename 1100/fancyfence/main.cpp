#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << ((2*n) % (180-n) ? "NO" : "YES") << '\n';
    }
}
