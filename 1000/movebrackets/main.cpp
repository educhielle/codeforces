#include <iostream>

using namespace std;

inline int readint()
{
    int x = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        x = 10 * x + c - '0';
    }
    return x;
}

int main()
{
    int t = readint();
    while (t--)
    {
        int n = readint(), count = 0, top = 0;
        while (n--)
        {
            auto c = getchar();
            if (c == ')') count++;
            else count--;
            if (count > top) top = count;
        }
        getchar();
        cout << top << '\n';
    }
}
