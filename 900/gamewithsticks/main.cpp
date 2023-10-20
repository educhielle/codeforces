#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << ( min(m,n) & 1 ? "Akshat" : "Malvika") << '\n';
}
