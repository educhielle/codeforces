#include <iostream>
#include <string>

using namespace std;

int main()
{
    string n;
    cin >> n >> n;
    int anton = 0;
    for (auto c : n)
    {
        if ( c == 'A' ) anton++;
        else anton--;
    }
    if (anton > 0) cout << "Anton\n";
    else if (anton < 0) cout << "Danik\n";
    else cout << "Friendship\n";
}
