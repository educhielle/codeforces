#include <iostream>

using namespace std;

inline int readint()
{
    int x = 0;
    char c;
    while (((c = getchar()) >= '0') && (c <= '9'))
    {
        x = 10 * x + c - '0';
    }
    return x;
}

inline int readsum(const int & begin, const int & n)
{
    int sum = 0;
    for (int i=begin; i<n; i++) sum += readint();
    return sum;
}

int main()
{
    const int SIZE = 3;
    auto n = readint();
    int sum[SIZE];
    for (int i=0; i<SIZE; i++) sum[i] = readsum(i,n);
    for (int i=1; i<SIZE; i++) printf("%d\n", sum[i-1]-sum[i]);
}