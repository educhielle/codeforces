#include <iostream>
#include <string>

using namespace std;

inline bool is_capslock_on(const string & word)
{
    if (word.size() == 1 && word[0] >= 'a') return true;
    for (int i=1; i<word.size(); i++) if (word[i] >= 'a') return false;
    return true;
}

inline string invert(const string & word)
{
    const char offset = 'a' - 'A';
    string inv;
    for (auto c : word)
    {
        if (c >= 'a') inv += c-offset;
        else inv += c+offset;
    }
    return inv;
}

int main()
{
    string word;
    cin >> word;
    if (is_capslock_on(word)) cout << invert(word) << '\n';
    else cout << word << '\n';
}
