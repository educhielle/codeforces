#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long n, l;
    cin >> n >> l;
    vector<long> v(n);
    for (long i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    long radius = max(v[0]<<1, (l-v.back())<<1);
    for (long i=1; i<n; i++) radius = max(radius, abs(v[i]-v[i-1]));
    cout << (radius>>1) << (radius & 1 ? ".5\n" : "\n");
}
