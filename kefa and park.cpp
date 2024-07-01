#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int Size = 100005;
vector<long long> adj[Size];
bool vis[Size];
long long n, m, total = 0;
long long cc[Size];

void dfs(long long s, long long sum) {
    if (vis[s]) return;

    vis[s] = true;

    if (cc[s]) sum++;
    else sum = 0;

    if (sum > m) return;

    if (s != 1 && adj[s].size() == 1) {
        total++;
    }

    for (long long neighbor : adj[s]) {
        dfs(neighbor, sum);
    }
}

int main() {
    memset(vis, false, sizeof(vis));

    cin >> n >> m;

    for (long long i = 1; i <= n; ++i) {
        cin >> cc[i];
    }

    for (long long i = 0; i < n - 1; ++i) {
        long long u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << total << endl;

    return 0;
}
