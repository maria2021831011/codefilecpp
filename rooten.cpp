#include<bits/stdc++.h>
using namespace std;

const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> v[i][j];
            if(v[i][j] == 2) {
                vis[i][j] = 1;
            }
        }
    }

    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(v[i][j] == 2 && vis[i][j] == 1) {
                q.push({{i, j}, 0});
            }
        }
    }

    int t, tm = 0;

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        t = q.front().second;
        q.pop();

tm = max(tm, t);

        for(int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < m && v[nr][nc] == 1 && vis[nr][nc] == 0) {
                q.push({{nr, nc}, t + 1});
                vis[nr][nc] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 0 && v[i][j] == 1) {
                cout << "-1" << endl;

            }}
    }
                cout << tm << endl;





    return 0;
}
