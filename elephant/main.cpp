#include <iostream>

using namespace std;

int main()
{
    int x, steps = 0;
    cin >> x;
    for (int i=5; x; i--)
    {
        steps += x / i;
        x %= i;
    }
    cout << steps << '\n';
}
