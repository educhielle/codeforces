#include <iostream>
#include <unordered_map>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while (t--)
    {
        unordered_map<int64_t,uint64_t> map;
        int n;
        cin >> n;
        for (int64_t i=0; i<n; i++)
        {
            int64_t tmp;
            cin >> tmp;
            map[tmp-i]++;
        }
        uint64_t sum = 0;
        for (auto & e : map)
        {
            auto & k = e.second;
            sum += k * (k - 1) >> 1;
        }
        cout << sum << '\n';
    }
}
