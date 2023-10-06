#include <iostream>

using namespace std;

int main()
{
    int n, curr, prev, max, seq;
    prev = max = seq = 0;
    cin >> n;
    while (n--)
    {
        cin >> curr;
        if (curr >= prev) seq++;
        else
        {
            max = std::max(max, seq);
            seq = 1;
        }
        prev = curr;
    }
    max = std::max(max, seq);
    cout << max << '\n';
}
