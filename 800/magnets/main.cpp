#include <iostream>

using namespace std;

int main()
{
    int n, previous, ngroups = 1;
    cin >> n;
    cin >> previous;
    while (--n)
    {
        int current;
        cin >> current;
        if (current != previous) ngroups++;
        previous = current;
    }
    cout << ngroups << '\n';
}
