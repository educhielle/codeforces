#include <iostream>
#include <string>

using namespace std;

inline bool isLuckyDigit(char d)
{
    return d == '4' || d == '7';
}

int main()
{
    string n;
    cin >> n;
    char count = 0;
    for (auto c : n)
        if ( isLuckyDigit(c) ) count++;
    cout << ( isLuckyDigit(count+'0') ? "YES" : "NO" ) << '\n';
}
