
#include <bits/stdc++.h>
using namespace std;

const int mx = 10005;
const int INF = 1e9;
vector<pair<int, int>> adj[mx];
vector<int> dis(mx, INF);
vector<bool> vis(mx, false);
vector<int> parent(mx, -1);

int prims(int n, int source) {
    int cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dis[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (vis[u]) {
            continue;
        }

        cost += w;
        vis[u] = true;

        for (auto it : adj[u]) {
            int v = it.first;
            int w1 = it.second;

            if (!vis[v] && w1 < dis[v]) {
                dis[v] = w1;
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !adj[i].empty()) {
            return -1;
        }
    }

    return cost;
}

void printMST(int n) {
    for (int i = 1; i <= n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << " " << dis[i] << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int totalCost = prims(n, 1);

    if (totalCost == -1) {
        cout << "No spanning tree possible" << endl;
    } else {
        cout << "Total cost: " << totalCost << endl;
        printMST(n);
    }

    return 0;
}
