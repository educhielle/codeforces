#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word, lower, upper;
    cin >> word;
    int nlower = 0, nupper = 0;
    for (char c : word)
    {
        if (c >= 'a')
        {
            nlower++;
            lower += c;
            upper += c-32;
        }
        else
        {
            nupper++;
            lower += c+32;
            upper += c;
        }
    }
    cout << (nupper > nlower ? upper : lower) << '\n';
}
