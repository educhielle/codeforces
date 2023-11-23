#include <iostream>
#include <cstdlib>

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
    int n;
    cin >> n;
    int min = 1000000001, max = 0;
    uint64_t min_count, max_count;
    while (n--)
    {
        int x;
        cin >> x;
        if (x < min)
        {
            min = x;
            min_count = 1;
        }
        else if (x == min) min_count++;
        if (x > max)
        {
            max = x;
            max_count = 1;
        }
        else if (x == max) max_count++;
    }
    uint64_t count = min == max ? min_count * (max_count - 1) >> 1 : max_count * min_count;
    cout << (max - min) << ' ' << count << '\n';
}
