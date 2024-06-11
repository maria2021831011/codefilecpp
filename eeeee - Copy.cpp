
#include<bits/stdc++.h>
using namespace std;

void findpath(vector<vector<int>>& graph)
{
    int n = graph.size();
    vector<int> numofadj;

    for (int i = 0; i < n; i++)
        numofadj.push_back(accumulate(graph[i].begin(), graph[i].end(), 0));

    int startpoint = 0, numofodd = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (numofadj[i] % 2 == 1)
        {
            numofodd++;
            startpoint = i;
        }
    }

    if (numofodd > 2)
    {
        cout << "No Solution" << endl;
        return;
    }

    stack<int> stack;
    vector<int> path;
    int cur = startpoint;

    while (!stack.empty() || accumulate(graph[cur].begin(), graph[cur].end(), 0) != 0)
    {
        if (accumulate(graph[cur].begin(), graph[cur].end(), 0) == 0)
        {
            path.push_back(cur);
            cur = stack.top();
            stack.pop();
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (graph[cur][i] == 1)
                {
                    stack.push(cur);
                    graph[cur][i] = 0;
                    graph[i][cur] = 0;
                    cur = i;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < path.size(); i++)
        cout << path[i] << " -> ";
    cout << cur << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    findpath(adj);

    return 0;
}
