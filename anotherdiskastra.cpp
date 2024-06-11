#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll INF = LLONG_MAX;
ll k, n, m, s, d, u, v, w;
vector<pair<ll, ll>> edges[N];
ll dist[N];

void dijkstra() {
    set<pair<ll, ll>> pq;
    dist[s] = 0;
    pq.insert({0, s});

    while (!pq.empty()) {
        auto [d, u] = *pq.begin();
        pq.erase(pq.begin());

        for (auto &[v, w] : edges[u]) {
            if (dist[v] > dist[u] + w) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> k;
    while (k--) {
        cin >> n >> m >> s >> d;

        for (int i = 1; i <= n; ++i) {
            edges[i].clear();
            dist[i] = INF;
        }

        while (m--) {
            cin >> u >> v >> w;
            w += 12;
            edges[u].emplace_back(v, w);
            edges[v].emplace_back(u, w);
        }

        dijkstra();
        cout << dist[d] << endl;
    }

    return 0;
}
