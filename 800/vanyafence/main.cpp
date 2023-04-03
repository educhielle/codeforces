#include <iostream>

using namespace std;

int main()
{
    int n, h;
    cin >> n >> h;
    int width = 0;
    while (n--)
    {
        int f;
        cin >> f;
        if (f > h) width += 2;
        else width++;
    }
    cout << width << '\n';
}
