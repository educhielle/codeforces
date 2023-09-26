#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string hello = "hello";
    string s;
    cin >> s;
    int idx = 0;
    for (int i=0; i<s.size() && idx < hello.size(); i++)
        if (s[i] == hello[idx]) idx++;
    cout << (idx == hello.size() ? "YES\n" : "NO\n");
}
