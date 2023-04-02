#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, t;
    string line;
    cin >> n >> t >> line;
    while (t--)
    {
        string newLine;
        for (int i=1; i<line.size(); i++)
        {
            if (line[i-1] == 'B' and line[i] == 'G')
            {
                newLine += "GB";
                i++;
            }
            else newLine += line[i-1];
        }
        if (newLine.size() < line.size())
            newLine += line[line.size()-1];
        line = newLine;
    }
    cout << line << '\n';
}
