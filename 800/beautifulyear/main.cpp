#include <iostream>

using namespace std;

bool distinctDigits(int x)
{
    bool digit[10] = {};
    while (x)
    {
        auto d = x % 10;
        if ( digit[d] ) return false;
        digit[d] = true;
        x /= 10;
    }
    return true;
}

int main()
{
    int x, y;
    cin >> y;
    for (x = y+1; !distinctDigits(x); x++);
    cout << x << '\n';
}
