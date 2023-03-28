#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int i=k;
    int score;
    while (i)
    {
        cin >> score;
        if (score <= 0) break;
        i--;
    }
    if (i) cout << (k-i) << '\n';
    else
    {
        int count = k-i;
        int lscore;
        while (cin >> lscore)
        {
            if (lscore < score) break;
            count++;
        }
        cout << count << '\n';
    }
}
