#include <iostream>

using namespace std;

int main()
{
    int n, ncoins[101] = {}, half = 0;
    cin >> n;
    while (n--)
    {
        int i;
        cin >> i;
        ncoins[i]++;
        half += i;
    }
    half /= 2;
    int value = 0, r = 0;
    for (int i=100; i>=0; i--)
    {
        while ( ncoins[i] )
        {
            value += i;
            r++;
            if (value > half)
            {
                cout << r << '\n';
                return 0;
            }
            ncoins[i]--;
        }
    }
}
