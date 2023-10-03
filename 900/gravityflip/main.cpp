#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int SIZE = 101;
    vector<int> v(SIZE, 0);
    int n, i;
    cin >> n;
    while (n--)
    {
        cin >> i;
        v[i]++;
    }
    for (i=1; i<v.size() && !v[i]; i++);
    v[i]--;
    cout << i;
    for (; i<v.size(); i++)
        while (v[i]--) cout << ' ' << i;
    cout << '\n';
}
