#include <iostream>

using namespace std;

int main()
{
    string line;
    cin >> line;
    int count[] = {0, 0, 0, 0};
    int i;
    for (i=0; i<line.size(); i+=2)
        count[line[i]-'0']++;
    for (i=1; i<4; i++)
    {
        if (count[i])
        {
            count[i]--;
            cout << i;
            break;
        }
    }
    for (i=1; i<4; i++)
        while (count[i]--) cout << "+" << i;
    cout << '\n';
}
