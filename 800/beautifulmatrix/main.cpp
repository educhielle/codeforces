#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int value, pos = 0;
    while (cin >> value)
    {
        if (value) break;
        pos++;
    }
    int row = pos / 5;
    int col = pos % 5;
    cout << ( abs(row-2) + abs(col-2) ) << '\n';
}
