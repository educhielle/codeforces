#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n+1];
    for (int i=1; i<=n; i++)
    {
        int t;
        cin >> t;
        v[t] = i;
    }
    cout << v[1];
    for (int i=2; i<=n; i++) cout << ' ' << v[i];
    cout << '\n';
}
