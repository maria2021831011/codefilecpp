#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int find(vector<int>& parent, int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent, parent[x]);
}

bool unite(vector<int>& parent, vector<int>& size, int x, int y) {
    x = find(parent, x);
    y = find(parent, y);
    if (x == y)
        return false;
    if (size[x] > size[y])
        swap(x, y);
    parent[x] = y;
    size[y] += size[x];
    return true;
}

long long kruskal(int N, vector<pair<long long, pair<int, int>>>& edges) {
    sort(edges.begin(), edges.end());
    long long ans = 0;
    vector<int> parent(N + 1);
    vector<int> size(N + 1, 1);
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (const auto& e : edges) {
        if (unite(parent, size, e.second.first, e.second.second))
            ans += e.first;
    }
    return (size[find(parent, 1)] == N ? ans : -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<long long, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        edges.push_back({ c, {a, b} });
    }
    long long ans = kruskal(n, edges);
    if (ans >= 0) {
        cout << ans;
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}
