#include <iostream>
#include <cmath>
#include <cstdlib>
#include <unordered_map>
#include <vector>

using namespace std;

uint64_t powm(uint64_t b, uint64_t e, uint64_t m)
{
    uint64_t r = 1;
    b %= m;
    while (e)
    {
        if (e & 1) r = (r * b) % m;
        e = e >> 1;
        b = (b*b) % m;
    }
    return r;
}

bool millerRabin(uint64_t d, uint64_t n)
{
    uint64_t a = 2 + rand() % (n - 4);
    uint64_t x = powm(a, d, n);
    if (x == 1 || x == n-1) return true;
    
    while (d != n-1)
    {
        x = (x * x) % n;
        d <<= 1;
        if (x == 1) return false;
        if (x == n-1) return true;
    }
    return false;
}

bool isPrime(uint64_t n, uint64_t k)
{
    if (n <= 1 || n == 4)  return false;
    if (n <= 3) return true;

    uint64_t d = n - 1;
    while (!(d & 1)) d >>= 1;

    while (k--)
        if (!millerRabin(d, n)) return false;
    return true;
}

bool isTPrime(uint64_t x)
{
    auto sq = sqrt(x);
    uint64_t isq = sq;
    if (isq != sq) return false;
    return isPrime(isq, 4); // k is the error probability as in 4^(-k)
}

int main()
{
    ios_base::sync_with_stdio(false); // fast io
    int n;
    cin >> n;
    while (n--)
    {
        uint64_t x;
        cin >> x;
        cout << (isTPrime(x) ? "YES" : "NO") << '\n';
    }
}
