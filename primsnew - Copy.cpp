#include<bits/stdc++.h>
using namespace std;
const int N=1e3+3;
const int INF=1e9;

vector<pair<int,int>>adj[N];
vector<bool>vis(N,false);
vector<int>dis(N,INF);
vector<int>parent(N,-1);

int prims(int start) {
    int cost = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    dis[start] = 0;
    pq.push({0,start});
    while(!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop(); // Pop the top element from the priority queue
        if(vis[u]) continue;

        vis[u] = true;
        cost += w;
        for(auto it : adj[u]) {
            int v = it.first;
            int w1 = it.second;
            if(!vis[v] && w1 < dis[v]) {
                dis[v] = w1;
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
    for(int i = 0; i < N; i++) {
        if(!vis[i] && adj[i].size() > 0) {
            return -1; // Graph is disconnected
        }
    }
    return cost;
}

void print(int start) {
    int sum = 0;
    for(int i = 0; i < parent.size(); i++) {
        if(i != start && parent[i] != -1) {
            cout << parent[i] << " - " << i << ": " << dis[i] << endl;
            sum += dis[i];
        }
    }
    cout << "Total cost: " << sum << endl;
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int total = prims(start);
    if(total == -1) {
        cout << "Graph is disconnected" << endl;
    } else {
        print(start);
    }
    return 0;
}
