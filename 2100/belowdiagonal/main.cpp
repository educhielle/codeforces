#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int nSwaps = 0;
vector<string> actions;

class BigInteger
{
    private:
        vector<uint64_t> v;

        static const int typesize = sizeof(uint64_t);
        inline static int bitsize = typesize;
        inline static int size = 1;

    public:
        BigInteger() : v(size, 0) {}

        bool operator<(const BigInteger & a) const
        {
            for (int i=size-1; i>=0; i--)
            {
                if (v[i] < a.v[i]) return true;
                else if (v[i] > a.v[i]) return false;
            }
            return false;
        }

        bool operator[](int idx) const
        {
            auto i = idx / typesize;
            auto j = idx % typesize;
            return (v[i] >> j) & 1;
        }

        void setBit(int idx)
        {
            auto i = idx / typesize;
            auto j = idx % typesize;
            v[i] |= 1 << j;
        }

        static void setBitsize(int bitsize)
        {
            BigInteger::bitsize = bitsize;
            BigInteger::size = bitsize / typesize + int(bitsize % typesize != 0);
        };

        friend ostream & operator<<(ostream & os, const BigInteger & a)
        {
            for (int i=0; i<bitsize; i++)
                os << a[i];
            return os;
        }
};

struct Coordinates
{
    int i;
    int j;

    Coordinates(int x, int y) : i(x), j(y) {}
};

void print(const vector<BigInteger> & v)
{
    for (const auto & e : v) cout << e << '\n';
    cout << '\n';
}

inline void swapRC(int rc, int p1, int p2)
{
    if (p1 != p2)
    {
        nSwaps++;
        stringstream ss;
        ss << rc << ' ' << (p1+1) << ' ' << (p2+1);
        actions.push_back( ss.str() );
    }
}

int main()
{
    int n;
    cin >> n;
    BigInteger::setBitsize(n);

    // load coordinates
    vector<Coordinates> vc;
    vector<bool> js(n, false);
    int counter = n;
    while (--counter)
    {
        int i, j;
        cin >> i >> j;
        vc.push_back( Coordinates(--i, --j) );
        js[j] = true;
    }


    // count the number of zero columns
    int nZeroCols = 0;
    for (int j=0; j<n; j++) nZeroCols += int( !js[j] );

    // make the last columns have only zeros
    for (int j=0; j<nZeroCols; j++)
    {
        int zeroCol;
        for (zeroCol=0; zeroCol < (n-j) && js[zeroCol]; zeroCol++); // find column with zeros
        auto idx = n-j-1;
        if (zeroCol != idx)
        {
            swapRC(2, zeroCol, idx); // append action to swap columns
            swap(js[zeroCol], js[idx]);
            for (auto & c : vc) if (c.j == idx) c.j = zeroCol; // swap coordinates of last column and zero column
        }
    }

    vector<BigInteger> rows(n);
    for (auto c : vc) rows[c.i].setBit(c.j); // set the big integers bits
    // print(rows);

    // sort BigInteger values, it is equivalent to organizing the matrix using row swaps
    for (int i=0; i<n-1; i++)
    {
        auto pos = i;
        for (int j=i; j<n; j++)
            if (rows[j] < rows[pos]) pos = j;
        swapRC(1, i, pos);  // append action to swap rows
        swap(rows[i], rows[pos]); // actually swap the values
        // print(rows);
    }

    // print actions
    cout << nSwaps << '\n';
    for (auto & action : actions) cout << action << '\n';
}
