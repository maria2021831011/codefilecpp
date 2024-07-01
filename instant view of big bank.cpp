
#include<bits/stdc++.h>
using namespace std;

int dis[2005];
bool vIs[1005], VIS[1005];
vector<int> ulta[2005];

void cycle(int ind) {
    VIS[ind] = true;
    for (auto t : ulta[ind]) {
        if (!VIS[t]) {
            cycle(t);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, r = 0;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            ulta[i].clear();
            VIS[i] = false;
        }

        vector<pair<int, pair<int, int>>> edge;
        for (int i = 0; i < m; i++) {
            int aa, bb, edg;
            cin >> aa >> bb >> edg;
            ulta[bb].push_back(aa);
            edge.push_back({edg, {bb, aa}});
        }

        for (int i = 0; i < n; i++) {
            dis[i] = 1e8;
        }
        dis[0] = 0;

        for (int i = 0; i < n; i++) {
            for (auto t : edge) {
                dis[t.second.second] = min(dis[t.second.second], dis[t.second.first] + t.first);
            }
        }

        int lp = 1;
        while (lp--) {
            for (auto t : edge) {
                if (dis[t.second.second] == -1e8) continue;
                if (dis[t.second.second] > dis[t.second.first] + t.first) {
                    dis[t.second.second] = -1e8;
                    cycle(t.second.first);
                }
            }
        }

        vector<int> ans;
        cout << "Case " << ++r << ": ";
        for (int i = 0; i < n; i++) {
            if (VIS[i]) ans.push_back(i);
        }

        if (ans.empty()) {
            cout << "impossible\n";
        } else {
            for (auto t : ans) cout << t << " ";
            cout << "\n";
        }
    }

    return 0;
}
