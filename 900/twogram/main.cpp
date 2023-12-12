#include <iostream>
#include <vector>

using namespace std;

int main()
{
    unsigned n, i, max=0, maxi;
    vector<int> map(676,0);
    cin >> n;
    getchar();
    i = getchar() - 65;
    while (--n)
    {
        i = 26*(i % 26) + getchar() - 65;
        map[i]++;
        if (map[i] > max)
        {
            max = map[i];
            maxi = i;
        }
    }
    cout << char(maxi / 26 + 65) << char(maxi % 26 + 65) << '\n';
}
