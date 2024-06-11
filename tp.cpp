
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> in_degree;

vector<int> topological_sort(int n) {
    vector<int> order;
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0)
                q.push(v);
        }
    }

    return order;
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    in_degree.assign(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        in_degree[b]++;
    }

    vector<int> order = topological_sort(n);

    if (order.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int course : order) {
            cout << course << " ";
        }
        cout << "\n";
    }

    return 0;
}
