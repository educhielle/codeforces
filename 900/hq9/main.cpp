#include <iostream>
#include <string>

using namespace std;

int main()
{
    string p;
    cin >> p;
    for (auto c : p)
    {
        if (c == 'H' || c == 'Q' || c == '9')
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}
