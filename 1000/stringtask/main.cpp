#include <iostream>
#include <string>

using namespace std;

inline bool isVowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main()
{
    string word_in, word_out = string();
    cin >> word_in;
    for (auto c : word_in)
    {
        c = tolower(c);
        if ( !isVowel(c) )
            word_out += "." + string(1,c);
    }
    cout << word_out << '\n';
}
