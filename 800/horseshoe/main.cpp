#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main()
{
    const int N = 4;
    int n = N;
    uint64_t s;
    vector<uint64_t> v;
    while (n--)
    {
        cin >> s;
        if (find(v.begin(), v.end(), s) == v.end()) v.push_back(s);
    }
    cout << (N-v.size()) << '\n';
}
