#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, s;
    vector<int> g(5); // number of groups of size 'i' for 1 <= i <= 4
    cin >> n;
    while (n--)
    {
        cin >> s; // read size of a group
        g[s]++;   // increment of the counter with the number of groups of size 's'
    }

    int t = g[4];  // each g[4] needs a taxi
    t += g[2] / 2; // two g[2]s add to 4
    g[2] &= 1;     // g[2] may be odd
    if (g[3] >= g[1])
        t += g[3] + g[2]; // g[3] cannot be combined with g[2]
    else
    {
        g[1] += -g[3] + (g[2] << 1); // g[1]+g[3] = 1 taxi, g[2] = 2*g[1]
        t += g[3] + (g[1] >> 2) + ((g[1] & 3) != 0); // add the taxi numbers
    }
    
    cout << t << '\n';
}
