#include <iostream>

using namespace std;

void print(int v[], int k, int i, int sum, int pos, int minsum)
{
    cout << "{";
    for (int j=0; j<k; j++) cout << ' ' << v[j];
    cout << " }\t" << i << '\t' << sum << '\t' << pos << '\t' << minsum << '\n';
}

int main()
{
    int n, k;
    cin >> n >> k;
    int v[k], sum = 0, i;
    for (i=0; i<k; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    int minsum = sum, pos = k-1;
    // print(v, k, i, sum, pos, minsum);
    for (; i<n; i++)
    {
        int idx = i % k;
        sum -= v[idx];
        cin >> v[idx];
        sum += v[idx];
        if (sum < minsum)
        {
            minsum = sum;
            pos = i;
        }
        // print(v, k, i, sum, pos, minsum);
    }
    cout << (pos-k+2) << '\n';
}
