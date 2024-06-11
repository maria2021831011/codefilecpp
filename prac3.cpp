
#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> v;
vector<int> dis;

void dijkstra(int start) {
    dis.assign(v.size(), 1e9);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    dis[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        int w = pq.top().first;
        int n = pq.top().second;
        pq.pop();
        for (auto it : v[n]) {
            int w1 = it.first;
            int n1 = it.second;
            if (dis[n1] > w1 + dis[n]) {
                dis[n1] = w1 + dis[n];
                pq.push({dis[n1], n1});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, k, w;
        cin >> u >> k>> w;
        v[u].push_back({w, k});
        v[k].push_back({w, u});
    }
    dijkstra(0);
    for (int i = 0; i < n; i++) {
        cout << "Distance to node " << i << ": " << dis[i] << endl;
    }
    return 0;
}
