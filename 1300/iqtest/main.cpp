#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a;
    cin >> a >> b >> c;
    a = ((a^b) & 1) | (((a^c) & 1) << 1) | (((b^c) & 1) << 2);
    if (a)
    {
        cout << (a>>1) << '\n';
        return 0;
    }

    b &= 1;
    for (a=4; (cin >> c) && (c & 1) == b; a++);
    cout << a << '\n';
}
