#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<ll, ll>;
using iii = tuple<ll, ll, ll>;

const int MAX{310};
const ll oo{1LL << 62};

ll dist[MAX][MAX], fuel[MAX];

vector<ii> adj[MAX];
bitset<MAX> processed;

void dijkstra(int s, ll N, ll L)
{
    for (ll i = 1; i <= N; ++i)
        dist[s][i] = fuel[i] = oo;

    dist[s][s] = 0;
    fuel[s] = L;
    processed.reset();

    priority_queue<iii, vector<iii>, greater<iii>> pq;
    pq.push(iii(0, -L, s));

    while (not pq.empty())
    {
        auto [d, f, u] = pq.top();
        pq.pop();

        if (processed[u])
            continue;

        processed[u] = true;

        for (const auto &[v, c] : adj[u])
        {
            if (c <= fuel[u] and (dist[s][v] > dist[s][u] or
                                  (dist[s][v] == dist[s][u] and fuel[u] - c > fuel[v])))
            {
                dist[s][v] = dist[s][u];
                fuel[v] = fuel[u] - c;
                pq.push(iii(dist[s][v], -fuel[v], v));
                continue;
            }

            if (c <= L and (dist[s][v] > dist[s][u] + 1 or
                            (dist[s][v] == dist[s][u] + 1 and L - c > fuel[v])))
            {
                dist[s][v] = dist[s][u] + 1;
                fuel[v] = L - c;
                pq.push(iii(dist[s][v], -fuel[v], v));
            }
        }
    }
}

int main()
{

    int n, m, l, q;

    cin >> n >> m >> l;

    int a, b, c;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        adj[a].push_back(ii(b, c));
        adj[b].push_back(ii(a, c));
    }

    cin >> q;
    for (int s = 1; s <= n; ++s)
        dijkstra(s, n, l);

    int s, t;
    for (int i = 0; i < q; i++)
    {
        cin >> s >> t;
        cout << (dist[s][t] == oo ? -1 : dist[s][t]) << endl;
    }
    return 0;
}