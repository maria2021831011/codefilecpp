#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int INF = 1e9;

vector<pair<int, int>> adj[N];
vector<int> parent(N, -1), dis(N, INF);
vector<bool> vis(N, false);

void prim(int source) {
    int cost = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dis[source] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (vis[u])
            continue;

        vis[u] = true;
        cost += w;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!vis[v] && weight < dis[v]) {
                dis[v] = weight;
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }



}

void printMST(int source) {

    int totalCost = 0;
    for (int i = 1; i < parent.size(); ++i) {
        if (i != source && parent[i] != -1) {

            totalCost += dis[i];
        }
    }
    cout  << totalCost << endl;
}

int main() {
    int n, m;
  cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source = 1;
     prim(source);

        printMST(source);

    return 0;
}
