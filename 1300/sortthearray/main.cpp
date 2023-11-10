#include <iostream>

using namespace std;

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main()
{
    fastIO();
    int n;
    cin >> n; // read array size

    int curr, prev, ante = 0;
    cin >> prev; // read first element

    int begin = 1, end = 1;
    int seq_prev, seq_first, seq_last, seq_post;
    bool is_decreasing = false, was_decreasing = false, done_decreasing = false;
    for (int i=1; i<n; i++)
    {
        cin >> curr; // read current element

        is_decreasing = curr < prev || (curr == prev && is_decreasing);

        if (done_decreasing && is_decreasing) // two decreasing sequences
        {
            cout << "no\n";
            return 0;
        }

        if (!was_decreasing && is_decreasing)
        {
            begin = i;
            seq_prev  = ante;
            seq_first = prev;
        }
        else if (was_decreasing && !is_decreasing)
        {
            done_decreasing = true;
            end = i;
            seq_last = prev;
            seq_post = curr;
            if (seq_prev > seq_last || seq_first > seq_post)
            {
                cout << "no\n";
                return 0;
            }
        }

        was_decreasing = is_decreasing;
        ante = prev;
        prev = curr;
    }

    if (is_decreasing)
    {
        end = n;
        seq_last = prev;
        if (seq_prev > seq_last)
        {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\n" << begin << ' ' << end << '\n';
}
