
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>vis;
void bfs(int start)
{queue<int>q;
vis[start]=1;
q.push(start);
while(!q.empty())
{
    int u=q.front();
    cout<<u<<" ";
    q.pop();
    for(auto it:adj[u])
    {
        if(vis[it]==0)
        {vis[it]=1;
            q.push(it);
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
    bfs(1);
}
