
#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> pii;
const ll INF = 1e9;
vector<vector<pii>> ad;

void dist(int start, int n) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<ll> dis(n + 10, INF);
    vector<ll> m(n + 10, -1);
    dis[start] = 0;
    pq.push({0, start});
    while (!pq.empty()) {
        ll w = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        for (auto it : ad[u]) {
            ll w1 = it.first;
            ll v = it.second;
            if (dis[u] + w1 < dis[v]) {
                m[v] = u;
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});
            }
        }
    }
    ll y = n;
    if (m[y] == -1) {
        cout << "-1" << endl;
    } else {
        vector<ll> ans;
        while (y != -1) {
            ans.push_back(y);
            y = m[y];
        }
        reverse(ans.begin(), ans.end());
        cout << dis[n] << endl;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;
    ad.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        ll v, u, w;
        cin >> u >> v >> w;
        ad[u].push_back({w, v});
        ad[v].push_back({w, u});
    }
    dist(1, n);
    return 0;
}
