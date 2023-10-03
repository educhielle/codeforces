#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Dragon
{
    int strength;
    int bonus;
    bool operator <(const Dragon & a) { return (strength < a.strength); }
};

int main()
{
    int s, n; // strength and number of dragons
    cin >> s >> n;
    vector<Dragon> dragons(n);
    while (n--) cin >> dragons[n].strength >> dragons[n].bonus;
    sort(dragons.begin(), dragons.end());
    for (n=0; n<dragons.size() && s > dragons[n].strength; s += dragons[n++].bonus);
    cout << (n == dragons.size() ? "YES" : "NO") << '\n';
}
