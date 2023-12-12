#include <iostream>

using namespace std;

int main()
{
    int a, b, r, s;
    cin >> a >> b;
    for (r=s=0; a;)
    {
        s += a;
        a += r;
        r = a % b;
        a /= b;
    }
    cout << s << '\n';
}
