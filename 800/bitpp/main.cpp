#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    auto nlines = stoi(line);
    int value = 0;
    while (nlines--)
    {
        getline(cin, line);
        if (line[1] == '+') value++;
        else value--;
    }
    cout << value << '\n';
}
