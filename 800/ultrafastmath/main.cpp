#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a;
    cin >> b;
    for (int i=0; i< a.size(); i++) cout << (a[i] != b[i]);
    cout << '\n';
}
