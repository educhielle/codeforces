#include <iostream>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    int64_t sign = n & 1;
    int64_t a = (n / 2) + sign;
    if (sign) a = -a;
    cout << a << '\n';
}
