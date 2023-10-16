#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int MAX_DIFF = 1000;
    int n, m;
    cin >> n >> m;
    vector<int> f(m);
    while (m--) cin >> f[m];
    sort(f.begin(), f.end());
    int diff = MAX_DIFF, pos;
    for (int i=n-1; i<f.size(); i++)
    {
        int tmp = f[i]-f[i-n+1];
        if (tmp < diff) diff = tmp;
    }
    cout << diff << '\n';
}
