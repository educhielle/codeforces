#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t = 0, x;
    vector<int> v(5);
    cin >> n;
    while (n--)
    {
        cin >> x;
        v[x]++;
    }

    int r = v[4];
    r += v[2] / 2;
    v[2] &= 1;
    if (v[3] >= v[1])
        r += v[3] + v[2];
    else
    {
        v[1] += -v[3] + (v[2] << 1);
        r += v[3] + (v[1] >> 2) + ((v[1] & 3) != 0);
    }
    
    cout << r << '\n';
}
