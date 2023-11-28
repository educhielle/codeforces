#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

inline int dist(int ax, int ay, int bx, int by)
{
    auto dx = ax - bx;
    auto dy = ay - by;
    return dx * dx + dy * dy;
}

int main()
{
    fastIO();
    int t;
    cin >> t;
    while (t--)
    {
        int px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;
        auto wa = max(dist(ax,ay,px,py), dist(ax,ay,0,0));
        auto wb = max(dist(bx,by,px,py), dist(bx,by,0,0));
        auto wt = double( dist(ax,ay,bx,by) ) / 4;
        auto wc = max(wt, double( max(dist(ax,ay,0,0),dist(bx,by,px,py)) ));
        auto wd = max(wt, double( max(dist(bx,by,0,0),dist(ax,ay,px,py)) ));
        cout << setprecision(8) << sqrt(min(double( min(wa,wb) ),min(wc,wd))) << '\n';
    }
}
