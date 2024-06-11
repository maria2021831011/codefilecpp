
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[] = {-1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

void fillcolor(int x, int y, vector<vector<int>>& v, vector<vector<int>>& vis, int n, int m, int newColor) {
    int oldColor = v[x][y];
    vis[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});
    v[x][y] = newColor;
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nrow = row + dx[k];
            int ncol = col + dy[k];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && v[nrow][ncol] == oldColor) {
                vis[nrow][ncol] = 1;
                v[nrow][ncol] = newColor;
                q.push({nrow, ncol});
            }
        }
    }
}

int main() {
    int n, m, x, y, c;
    cin >> n >> m >> x >> y >> c;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> vis(n, vector<int>(m, 0));
    fillcolor(x, y, v, vis, n, m, c);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
