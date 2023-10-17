#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string,int> db;
    while (n--)
    {
        string name;
        cin >> name;
        if (db[name]) cout << name << db[name] << '\n';
        else cout << "OK\n";
        db[name]++;
    }
}
