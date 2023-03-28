#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    const int size = 'z'-'a'+1;
    vector<bool> used(size, false);
    string word;
    cin >> word;
    for (char c : word) used[c-'a'] = true;
    bool male = false;
    for (bool b : used) male ^= b;
    cout << (male ? "IGNORE HIM!" : "CHAT WITH HER!") << '\n';
}
