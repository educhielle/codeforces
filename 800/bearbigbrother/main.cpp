#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    float a, b;
    cin >> a >> b;
    float yf = log(b/a) / log(1.5);
    int   yi = ceil(yf);
    if ( int(yf) == yi ) yi++;
    cout << yi << '\n';
}
