
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = 1e9;
typedef pair<ll, ll> pii;
vector<vector<pii> >adjList;
void dijkstra(int s, int t) {
map<ll,ll>m;
priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<ll>dis(t+ 10, INF);
dis[s] = 0;
  pq.push({0, s});
    while (!pq.empty()) {
            ll w=pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        for (auto &p : adjList[u]) {
            ll v = p.second;
            ll w1 = p.first;
            if (dis[u] + w1 < dis[v]) {
                m[v]=u;
                dis[v] = dis[u] + w1;
                pq.push({dis[v], v});

            }
        }
    }ll y=t;
    if(m[y]==0)
    {
        cout<<"-1"<<endl;
    }else{
    vector<ll>ans;
    m[1]=-1;
    while(y!=-1){
        ans.push_back(y);
        y=m[y];
    }reverse(ans.begin(),ans.end());
    for(auto it:ans)
    {
        cout<<it<<" ";}
        cout<<endl;


    }
}

void solve() {
    ll m,n;
    cin >> n >> m;
adjList.resize(n+1);
    ll u, v, w;

    for(int i=1;i<=m;i++){
        cin >> u >> v >> w;
        adjList[u].push_back({w, v});
        adjList[v].push_back({w, u});
    }
dijkstra(1, n);

}
int main()
{solve();
}
