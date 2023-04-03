#include <iostream>
#include <string>

using namespace std;

int main()
{
    string situation;
    cin >> situation;
    bool dangerous = false;
    int count = 0;
    char p = ' ';
    for (auto c : situation)
    {
        if (c == p)
        {
            if (++count >= 7)
            {
                dangerous = true;
                break;
            }
        }
        else
        {
            count = 1;
            p = c;
        }
    }
    cout << ( dangerous ? "YES" : "NO" ) << '\n';
}
