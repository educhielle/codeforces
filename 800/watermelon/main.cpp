#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    auto n = stoi(line);
    cout << ( n & 1 || n == 2 ? "NO" : "YES" ) << '\n';
}
