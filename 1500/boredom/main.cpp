#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    const uint64_t MAX_N = 100001;
    uint64_t n, max_idx = 0;
    cin >> n;
    vector<uint64_t> v(MAX_N, 0);
    while (n--)
    {
        uint64_t tmp;
        cin >> tmp;
        v[tmp]++;
        max_idx = max(tmp, max_idx);
    }
    if (max_idx >= 2) v[2] <<= 1;
    for (uint64_t i=3; i<=max_idx; i++)
        v[i] = i * v[i] + max(v[i-3], v[i-2]);
    cout << max(v[max_idx-1], v[max_idx]) << '\n';
}
