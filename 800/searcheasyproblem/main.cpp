#include <iostream>

using namespace std;

int main()
{
    int n, h;
    cin >> n;
    while (n--)
    {
        cin >> h;
        if (h)
        {
            cout << "HARD\n";
            return 0;
        }
    }
    cout << "EASY\n";
}
