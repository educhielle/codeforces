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
            auto j = idx - i;
            return (v[i] >> j) & 1;
        }

        void setBit(int idx)
        {
            auto i = idx / typesize;
            auto j = idx - i;
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

void print(const vector<vector<bool>> & m)
{
    for (const auto v : m)
    {
        for (const auto e : v) cout << ' ' << e;
        cout << '\n';
    }
    cout << '\n';
}

void merge(vector<BigInteger> & v, int l, int m, int r)
{
    int lsize = m - l + 1;
    int rsize = r - m;
    vector<BigInteger> vl(lsize), vr(rsize);
    for (int i=0; i<lsize; i++) vl[i] = v[l+i];
    for (int j=0; j<rsize; j++) vr[j] = v[m+1+j];

    int i = 0, j = 0, k = l;
    while (i < lsize && j < rsize)
    {
        if (vl[i] < vr[j]) v[k++] = vl[i++];
        else v[k++] = vr[j++];
    }
    while (i < lsize) v[k++] = vl[i++];
    while (j < rsize) v[k++] = vr[j++];
}

void mergesort(vector<BigInteger> & v, int l, int r)
{
    if (l < r)
    {
        int m = l + (m-l) / 2;
        mergesort(v, l, m);
        mergesort(v, m+1, r);
        merge(v, l, m, r);
    }
}

void mergesort(vector<BigInteger> & v)
{
    int l = 0;
    int r = v.size() - 1;
    mergesort(v, l, r);
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

    // make the last column have only zeros
    int zeroCol;
    for (zeroCol=0; zeroCol < n && js[zeroCol]; zeroCol++); // find column with zeros

    vector<BigInteger> rows(n);
    for (auto c : vc)
    {
        if (c.j == n-1) c.j = zeroCol; // swap coordinates of last column and zero column
        rows[c.i].setBit(c.j); // set the big integers bits
    }
    swapRC(2, zeroCol, n-1); // append action to swap columns
    // print(rows);

    // sort BigInteger values, it is equivalent to organizing the matrix using row swaps
    for (int i=0; i<n-1; i++)
    {
        auto pos = i;
        for (int j=1; j<n; j++)
            if (rows[j] < rows[pos]) pos = j;
        swapRC(1, i, pos);  // append action to swap rows
        swap(rows[i], rows[pos]); // actually swap the values
        // print(rows);
    }

    // print actions
    cout << nSwaps << '\n';
    for (auto & action : actions) cout << action << '\n';
}
