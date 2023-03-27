#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string line;
    while (n--)
    {
        cin >> line;
        if (line.size() <= 10)
            cout << line << '\n';
        else
            cout << line[0] << (line.size()-2) << line[line.size()-1] << '\n';
    }
}
