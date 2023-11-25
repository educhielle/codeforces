#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int64_t x, y, a, b;
        cin >> x >> y >> a >> b;
        int64_t px = abs(x);
        int64_t py = abs(y);
        int64_t r1 = (px + py) * a;
        int64_t l = min(px,py);
        int64_t h = px+py-l;
        int64_t r2 = l * b + (h-l) * a;
        cout << min(r1,r2) << '\n';
    }
}
