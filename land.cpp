
#include <bits/stdc++.h>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {0, -1, 1, -1, 1, -1, 0, 1};

void bfs(int i, int j, vector<vector<char>>& v, vector<vector<int>>& vis, int n, int m) {
    vis[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++) {
            int nrow = row + dx[k];
            int ncol = col + dy[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && v[nrow][ncol] == '1') {
                vis[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && v[i][j] == '1') {
                c++;
                bfs(i, j, v, vis, n, m);
            }
        }
    }
    cout << c << endl;
    return 0;
}
