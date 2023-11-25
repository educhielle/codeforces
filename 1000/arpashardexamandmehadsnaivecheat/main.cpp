#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (!n) n = 1;
    else
    {
        n &= 3;
        switch (n)
        {
            case 0: n = 6; break;
            case 1: n = 8; break;
            case 2: n = 4; break;
            case 3: n = 2;
        }
    }
    cout << n << '\n';
}
