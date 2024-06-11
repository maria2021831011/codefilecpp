#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 3;
const int INF = 1e9;

vector<pair<int, int>> adj[N];
vector<int> parent(N, -1), dis(N, INF);
vector<bool> vis(N, false);

int prim(int source) {
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

    // Check if all vertices are visited
    for (int i = 0; i < vis.size(); ++i) {
        if (!vis[i])
            return -1; // No MST found
    }

    return cost;
}

void printMST(int source) {
    cout << "Minimum Spanning Tree (MST):" << endl;
    int totalCost = 0;
    for (int i = 0; i < parent.size(); ++i) {
        if (i != source && parent[i] != -1) {
            cout << parent[i] << " -- " << i << " == " << dis[i] << endl;
            totalCost += dis[i];
        }
    }
    cout << "Total cost of MST: " << totalCost << endl;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter edges as 'source destination weight':" << endl;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int source = 0; // Assuming source is 0
    int totalCost = prim(source);
    if (totalCost == -1)
        cout << "No MST exists!" << endl;
    else
        printMST(source);

    return 0;
}
