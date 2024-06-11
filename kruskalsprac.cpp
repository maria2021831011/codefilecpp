
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<pair<int,int>,int>> adj;
vector<pair<pair<int,int>,int>> res;
vector<int> tree;
bool cmp(const pair<pair<int,int>,int>&a,const pair<pair<int,int>,int>&b)
{
    return a.second < b.second;
}
void kruskals()
{
    for(int i = 1; i <= n; i++) // Starting from 1
    {
        tree[i] = i;
    }
    sort(adj.begin(), adj.end(), cmp);
    for(auto it : adj)
    {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        if(tree[u] != tree[v])
        {
            res.push_back({{u, v}, w});
            int old = tree[u];
            int newk = tree[v];
            for(int i = 1; i <= n; i++) // Starting from 1
            {
                if(tree[i] == old)
                {
                    tree[i] = newk;
                }
            }
        }
    }
    int sum = 0;
    for(auto ans : res)
    {
        sum += ans.second;
        cout << ans.first.first << "-" << ans.first.second << ":" << ans.second << endl;
    }
    cout << sum << endl;
}
int main()
{
    cin >> n >> m;
    tree.resize(n + 1, 0); // Resize with (n+1)
    adj.resize(m);
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[i] = {{u, v}, w};
    }
    kruskals();
}
