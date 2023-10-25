#include <cctype>
#include <cstdio>
#include <iostream>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    const char nine = '9' + '0';
    char c = getchar();
    cout << char(c >= '5' && c <= '8' ? nine - c : c);
    while (isdigit(c = getchar())) cout << char(c >= '5' ? nine - c : c);
    cout << '\n';
}
