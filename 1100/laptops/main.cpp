#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool sorting_function(const pair<int,int> & a, const pair<int,int> & b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    while (n--) cin >> v[n].first >> v[n].second;
    sort(v.begin(), v.end(), sorting_function);
    for (int i=1; i<v.size(); i++)
    {
        if (v[i-1].second > v[i].second)
        {
            cout << "Happy Alex\n";
            return 0;
        }
    }
    cout << "Poor Alex\n";
}
