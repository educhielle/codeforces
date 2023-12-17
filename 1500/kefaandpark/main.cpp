#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int cat;
    vector<int> nodes;
};

inline void fastIO()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int count(const vector<Node> & v, int i, int m, int c)
{
    c = v[i].cat ? c + v[i].cat : 0;
    if (c > m) return 0;
    if (v[i].nodes.empty()) return 1;
    int sum = 0;
    for (const auto node : v[i].nodes) sum += count(v,node,m,c);
    return sum;
}

void cut(vector<Node> & v, int p, int i)
{
    int j,k;
    for (j=0,k=0; k<v[i].nodes.size(); k++)
        if (v[i].nodes[k] != p) v[i].nodes[j++] = v[i].nodes[k];
    if (j<k) v[i].nodes.pop_back();
    for (auto node : v[i].nodes) cut(v, i, node);
}

int main()
{
    fastIO();
    int n, m;
    cin >> n >> m;
    // build tree
    vector<Node> v(n+1);
    for (int i=1; i<=n; i++) cin >> v[i].cat;
    for (int i=1; i<n; i++)
    {
        int f, t;
        cin >> f >> t;
        v[f].nodes.push_back(t);
        v[t].nodes.push_back(f);
    }
    cut(v, 0, 1);
    // count using dfs
    cout << count(v, 1, m, 0) << '\n';
}
