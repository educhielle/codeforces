#include <iostream>
#include <unordered_map>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

inline void print(const unordered_map<int,int> & map)
{
    for (const auto & e : map)
    {
        if (e.second)
        {
            cout << e.first << '\n';
            break;
        }
    }
}

int main()
{
    fastIO();
    int n;
    cin >> n;
    unordered_map<int,int> map1;
    for (int i=0; i<n; i++) // read first compilation errors
    {
        int x;
        cin >> x;
        map1[x]++;
    }
    unordered_map<int,int> map2;
    for (int i=1; i<n; i++) // read second compilation errors
    {
        int x;
        cin >> x;
        map1[x]--;
        map2[x]++;
    }
    for (int i=2; i<n; i++) // read third compilation errors
    {
        int x;
        cin >> x;
        map2[x]--;
    }
    print(map1);
    print(map2);
}
