#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

inline int64_t ceil_div(int t, int b)
{
    return int64_t(t / b) + bool(t % b);
}

inline int clog2(int n)
{
    int r = 0;
    for (; n; n >>= 1) r++;
    return r;
}

template <class T> void print(const vector<T> & v)
{
    for (auto & e : v) cout << e << ' ';
    cout << '\n';
}

template <class T> void print(const vector<vector<T>> & v)
{
    for (int i=0; i<v.size(); i++)
    {
        for (int j=0; j<v[i].size(); j++)
            cout << v[i][j] << '\t';
        cout << '\n';
    }
}

inline vector<int> read(int n)
{
    vector<int> v(n);
    for (int i=0; i<n; cin >> v[i++]);
    return v;
}

class Hero
{
    private:
        int index;
        int health;
        int armor;

    public:
        Hero() : Hero(-1,0,0) {}
        Hero(int i, int h, int a) : index(i), health(h), armor(a) {}

        bool operator <(const Hero & a) const { return health != a.health ? health <  a.health : armor <  a.armor; }
        bool operator >(const Hero & a) const { return health != a.health ? health >  a.health : armor >  a.armor; }
        bool operator>=(const Hero & a) const { return health != a.health ? health >= a.health : armor >= a.armor; }

        int64_t calculate_rounds(int x) const { return ceil_div(armor, x) * health; }
        int get_index() const { return index; }

        friend ostream & operator <<(ostream & os, const Hero & hero)
        {
            return os << '{' << hero.index << ',' << hero.health << ',' << hero.armor << '}';
        }
};

class HeroPair
{
    private:
        Hero top, sec;

    public:
        HeroPair() : HeroPair(Hero(), Hero()) {}
        HeroPair(const Hero & hero) : HeroPair(hero, Hero()) {}
        HeroPair(const Hero & t, const Hero & s) : top(t), sec(s) {}
        HeroPair(const HeroPair & pair) : HeroPair(pair.top, pair.sec) {}

        // merge two HeroPairs keeping the one with more health
        HeroPair & operator +=(const HeroPair & pair)
        {
            const Hero *top_ptr, *sec_ptr;
            if (top >= pair.top)
            {
                top_ptr = &top;
                if (top.get_index() != pair.top.get_index())
                    if (sec >= pair.top) sec_ptr = &sec;
                    else sec_ptr = &pair.top;
                else
                    if (sec >= pair.sec) sec_ptr = &sec;
                    else sec_ptr = &pair.sec;
            }
            else
            {
                top_ptr = &pair.top;
                if (pair.sec >= top) sec_ptr = &pair.sec;
                else sec_ptr = &top;
            }
            top = *top_ptr;
            sec = *sec_ptr;
            
            return *this;
        }

        // merge two HeroPairs keeping the one with more health
        HeroPair operator +(const HeroPair & pair)
        {
            const Hero *top_ptr, *sec_ptr;
            if (top >= pair.top)
            {
                top_ptr = &top;
                if (top.get_index() != pair.top.get_index())
                    if (sec >= pair.top) sec_ptr = &sec;
                    else sec_ptr = &pair.top;
                else
                    if (sec >= pair.sec) sec_ptr = &sec;
                    else sec_ptr = &pair.sec;
            }
            else
            {
                top_ptr = &pair.top;
                if (pair.sec >= top) sec_ptr = &pair.sec;
                else sec_ptr = &top;
            }
            return HeroPair(*top_ptr, *sec_ptr);
        }

        bool operator !=(const HeroPair & pair) const { return top.get_index() != pair.top.get_index(); }

        int get_index() const { return top.get_index(); }

        void insert(const Hero & hero)
        {
            if (hero > sec) sec = hero;
            if (sec > top) swap(top, sec);
        }

        pair<int64_t,int64_t> rounds(int x)
        {
            return make_pair(top.calculate_rounds(x), sec.calculate_rounds(x));
        }

        int top_index() const { return top.get_index(); }

        friend ostream & operator <<(ostream & os, const HeroPair & pair)
        {
            return os << pair.top << 'x' << pair.sec;
        }
};

// calculate points for a given 'x'
inline pair<int,int64_t> calculate_points(const vector<vector<HeroPair>> & health_table, int max_armor, int x)
{
    HeroPair top;
    int64_t toptop_rounds = 0, topsec_rounds = 0, sectop_rounds = 0, secsec_rounds = 0;
    auto exp = clog2(x)-1;
    auto size = (1 << exp);
    auto offset = x-size;
    for (int a=1; a<=max_armor; a+=x)
    {
        auto pair = health_table[a][exp];
        if (a+offset <= max_armor && offset > 0)
            pair += health_table[a+offset][exp];
        auto [pairtop_rounds,pairsec_rounds] = pair.rounds(x);
        if ((pairtop_rounds == sectop_rounds ? pairsec_rounds > secsec_rounds : pairtop_rounds > sectop_rounds) && pair != top)
        {
            sectop_rounds = pairtop_rounds;
            secsec_rounds = pairsec_rounds;
            if (sectop_rounds > toptop_rounds)
            {
                top = pair;
                swap(toptop_rounds, sectop_rounds);
                swap(topsec_rounds, secsec_rounds);
            }
        }
    }
    return make_pair(top.get_index(), toptop_rounds - max(topsec_rounds, sectop_rounds));
}

// calculate points per 'x' and keep max per hero
inline vector<int64_t> calculate_points(int n, const vector<vector<HeroPair>> & health_table, int max_armor)
{
    vector<int64_t> points(n,0);
    for (int x=1; x<=max_armor; x++)
    {
        auto [idx,pts] = calculate_points(health_table, max_armor, x);
        if (pts > points[idx]) points[idx] = pts;
    }
    return points;
}

// create armor table with the best heroes per armor
inline vector<HeroPair*> create_armor_table(const vector<int> & health, const vector<int> & armor, int max_armor)
{
    vector<HeroPair*> armor_table(max_armor+1, nullptr);
    for (int i=0; i<armor.size(); i++)
    {
        const auto & a = armor[i];
        const auto & h = health[i];
        Hero hero(i,h,a);
        if (armor_table[a]) armor_table[a]->insert(hero);
        else armor_table[a] = new HeroPair(hero);
    }
    return armor_table;
}

// create a sparse table with the highest health per subset of armors
inline vector<vector<HeroPair>> create_health_table(const vector<HeroPair*> & armor_table, int max_armor)
{
    auto max_size = clog2(max_armor);
    vector<vector<HeroPair>> health_table(max_armor+1, vector<HeroPair>(max_size));
    for (int a=1; a<=max_armor; a++) // fill first column (when exp = 0)
    {
        if (armor_table[a] != nullptr)
            health_table[a][0] = *armor_table[a];
    }
    for (int exp=1; exp<max_size; exp++) // fill the remaining columns based on previous columns
    {
        int inc = 1 << (exp-1);
        for (int a=1; a<=max_armor; a++)
            health_table[a][exp] = a+inc <= max_armor ? health_table[a][exp-1] + health_table[a+inc][exp-1] : health_table[a][exp-1];
    }
    return health_table;
}

int main()
{
    ios_base::sync_with_stdio(false); // fast io
    int t;
    cin >> t; // number of tests
    while (t--)
    {
        int n;
        cin >> n; // number of heroes

        auto health = read(n); // read health values
        auto armor = read(n); // read armor values
        auto max_armor = *max_element(armor.begin(), armor.end()); // find max armor
        auto armor_table = create_armor_table(health, armor, max_armor);
        auto health_table = create_health_table(armor_table, max_armor); // slow
        auto points = calculate_points(n, health_table, max_armor); // slowest
        print(points);
    }
}