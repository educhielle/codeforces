#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int capacity = 0;
    int passangers = 0;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        passangers -= a;
        passangers += b;
        if (passangers > capacity) capacity = passangers;
    }
    cout << capacity << '\n';
}
