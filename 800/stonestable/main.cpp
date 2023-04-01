#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    cin >> line >> line;
    int count = 0;
    for (int i=1; i<line.size(); i++)
        if (line[i] == line[i-1]) count++;
    cout << count << '\n';
}
