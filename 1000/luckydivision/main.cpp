#include <iostream>

using namespace std;

inline bool isLuckyNumber(int n)
{
    while (n > 0)
    {
        int rem = n % 10;
        if (rem != 4 && rem != 7) return false;
        n /= 10;
    }
    return true;
}

inline int generateLuckyNumber(int radlen, int seed)
{
    int r = 0;
    while (radlen--)
    {
        r = 10 * r + 3 * (seed & 1) + 4;
        seed >>= 1;
    }
    return r;
}

int main()
{
    const int MAX_RADLEN = 3;
    int n;
    cin >> n;
    if ( isLuckyNumber(n) )
    {
        cout << "YES\n";
        return 0;
    }

    int lucky = 0;
    for (int len=1; len <= MAX_RADLEN; len++)
    {
        for (int i=0; i < (1<<len); i++)
        {
            lucky = generateLuckyNumber(len, i);
            if (!(n % lucky))
            {
                cout << "YES\n";
                return 0;
            }
        }
    }
    
    cout << "NO\n";
}
