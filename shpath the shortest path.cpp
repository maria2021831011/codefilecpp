
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10004;
const long long INF = 1e18;
vector<pair<int, int>> adj[MAX];
vector<long long> dist(MAX);

void spfa(int start, int n, int target) {
    fill(dist.begin(), dist.begin() + n + 1, INF);
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int current_dist = -pq.top().first;
        pq.pop();

        if (u == target) return;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int len = edge.second;
            if (current_dist + len < dist[v]) {
                dist[v] = current_dist + len;
                pq.push({-dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int n;
        cin >> n;

        unordered_map<string, int> city_to_index;
        for (int i = 1; i <= n; ++i) {
            string city;
            cin >> city;
            city_to_index[city] = i;

            int p;
            cin >> p;
            while (p--) {
                int nr, cost;
                cin >> nr >> cost;
                adj[i].emplace_back(nr, cost);
            }
        }

        int routes;
        cin >> routes;
        while (routes--) {
            string start_city, end_city;
            cin >> start_city >> end_city;
            int start = city_to_index[start_city];
            int end = city_to_index[end_city];

            spfa(start, n, end);
            cout << dist[end] << '\n';
        }

        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
        }
    }

    return 0;
}
