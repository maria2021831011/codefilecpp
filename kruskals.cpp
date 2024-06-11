#include <bits/stdc++.h>
using namespace std;
int n, m;
bool edgeComp(const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>& b) {
    return a.second < b.second;
}

vector<pair<pair<int, int>, int>> adj;
vector<int> tree_id;

vector<pair<pair<int, int>, int>> result;

void kruskals() {
    int cost = 0;
    for (int i = 0; i < n; i++)
        tree_id[i] = i;

    sort(adj.begin(), adj.end(), edgeComp);

    for (auto& e : adj) {
        int u = e.first.first;
        int v = e.first.second;
        int w = e.second;

        if (tree_id[u] != tree_id[v]) {
            cost += w;
            result.push_back({{u, v}, w});

            int old_id = tree_id[u], new_id = tree_id[v];
            for (int i = 0; i < n; i++) {
                if (tree_id[i] == old_id)
                    tree_id[i] = new_id;
            }
        }
    }

    int ans = 0;
    cout << "Following are the edges in the constructed MST" << endl;
    for (auto& e : result) {
        ans += e.second;
        cout << e.first.first << " " << e.first.second << " " << e.second << endl;
    }
    cout << "Minimum Cost Spanning Tree: " << ans << endl;
}

int main() {
    cin >> n >> m;
    tree_id.resize(n, 0);

    adj.resize(m);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        adj[i] = {{u, v}, w};
    }

    kruskals();

    return 0;
}
