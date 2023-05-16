#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

vector<ii> adj[100010];

int log2int(long long x)
{
    int res = 0;

    while (x > 1)
    {
        ++res;
        x >>= 1;
    }

    return res;
}

long long prim(int u, int n)
{
    ll cost = 0;

    set<ll> c;
    c.insert(u);

    priority_queue<ii, vector<ii>, greater<ii>> pq;

    for (auto [v, w] : adj[u])
        pq.push(ii(w, v));

    while (c.size() != n)
    {

        ll v, w;

        do
        {
            w = pq.top().first, v = pq.top().second;
            pq.pop();
        } while (c.count(v));

        cost += w;
        c.insert(v);

        for (auto [s, p] : adj[v])
        {
            pq.push({p, s});
        }
    }

    return cost;
}

int main()
{
    ios::sync_with_stdio(false);

    long long t, n, m, a, b, c;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int u = 1; u <= n; ++u)
            adj[u].clear();

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b >> c;

            c = log2int(c);
            adj[a].push_back(ii(b, c));
            adj[b].push_back(ii(a, c));
        }

        cout << prim(1, n) + 1 << '\n';
    }

    return 0;
}