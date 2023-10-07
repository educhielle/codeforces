#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string message[] = {"I hate", "I love"};
    int n;
    cin >> n;
    cout << message[0];
    for (int i=1; i<n; i++) cout << " that " << message[i&1];
    cout << " it\n";
}
