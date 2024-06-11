
#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long double ld;
typedef long long ll;
const int inf = 1e9;
int n, cur;
#define x first
#define y second
vector<vector<pair<int, int>>> sl;

void dfs(int v, vector<bool> &used) {
    used[v] = true;
    for (auto e : sl[v]) {
        int u = e.x, w = e.y;
        if (!used[u] && (cur | w) == cur) {
            dfs(u, used);
        }
    }
}

void cnt(int pw) {
    if (pw < 0) return;
    int d = (ll)1 << pw;
    cur -= d;
    vector<bool> used(n);
    dfs(0, used);
    for (bool b : used) {
        if (!b) {
            cur += d;
            break;
        }
    }
    cnt(pw - 1);
}

void solve() {
    cin >> n;
    int m;
    cin >> m;

    sl.assign(n, vector<pair<int, int>>(0));
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        sl[u].emplace_back(v, w);
        sl[v].emplace_back(u, w);
    }

    cur = 1;
    int bit = 0;
    while (cur < inf) {
        cur = 2 * cur + 1;
        bit++;
    }
    cnt(bit);

    cout << cur;
}

bool multi = true;

signed main() {
    int t = 1;
    if (multi) {
        cin >> t;
    }
    while (t--) {
        solve();
        cout << "\n";
    }
    return 0;
}
