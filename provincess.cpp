
#include <bits/stdc++.h>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<int>& vis) {
    vis[start] = 1;
    for (auto i : adj[start]) {
        if (!vis[i]) {
            dfs(i, adj, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> vis(n + 1, 0);
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            c++;
            dfs(i, adj, vis);
        }
    }
    cout << c << endl;
    return 0;
}
