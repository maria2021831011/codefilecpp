#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
void dfs(int start)
{stack<int>q;
vis[start]=1;
q.push(start);
while(!q.empty())
{
    int u=q.top();
    cout<<u<<" ";
    q.pop();
    for(auto it:adj[u])
    {
        if(vis[it]==0)
        {vis[it]=1;
            dfs(it);
        }
    }

}

}
int main()
{
    int n,m;
    cin>>n>>m;
    vis.assign(n+1,0);
    adj.resize(n+1);
    for(int i=0;i<m;i++)
    {int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
}
