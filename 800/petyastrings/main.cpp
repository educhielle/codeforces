#include <iostream>

using namespace std;

int main()
{
    int n;
    string s1, s2;
    cin >> s1 >> s2;
    for (int i=0; i<s1.size(); i++)
    {
        char c1 = s1[i];
        char c2 = s2[i];
        if (c1 >= 'a') c1 -= 32;
        if (c2 >= 'a') c2 -= 32;
        n = c1 - c2;
        if (!n) continue;
        n = n<0 ? -1 : 1;
        break;
    }
    cout << n << '\n';
}
