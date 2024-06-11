#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void bellmanford(int s, vector<vector<pair<int, int>>>& adj, int n) {
    vector<int> dis(n, 1e9);
    dis[s] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto it : adj[u]) {
                int v = it.first;
                int weight = it.second;
                if (dis[u] != 1e9 && dis[u] + weight < dis[v]) {
                    dis[v] = dis[u] + weight;
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (auto it : adj[u]) {
            int v = it.first;
            int weight = it.second;
            if (dis[u] + weight < dis[v]) {
                cout << "Negative cycle found\n";
                return;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance from source to vertex " << i << " is: " << dis[i] << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    bellmanford(0, adj, n);
    return 0;
}
