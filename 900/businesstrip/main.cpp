#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    const int size = 12;
    int k, a[size], r=0;
    cin >> k;
    for (int i=0; i<size; i++) cin >> a[i];
    sort(a, &a[size+1], [](int a, int b){ return a > b; });
    for (int i=0; i<size && k>0; i++, r++) k-=a[i];
    cout << (k > 0 ? -1 : r) << '\n';
}
