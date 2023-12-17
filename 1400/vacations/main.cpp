#include <iostream>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main()
{
    fastIO();
    const int MAX_LEN = 200;
    int n, count = 0;
    cin >> n >> ws;
    char a[MAX_LEN], p='0';
    cin.getline(a,MAX_LEN);
    for (int i=0; i<(n<<1); i+=2)
    {
        auto & c = a[i];
        if (c == '0' || c == p) { p = '0'; count++; }
        else if (c == '3') p = p == '0' ? '0' : 'c' - p;
        else p = c;
    }
    cout << count << '\n';
}
