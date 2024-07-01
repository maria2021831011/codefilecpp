#include<bits/stdc++.h>
using namespace std;
struct Edge {
    int x, y, v, enable;
};

vector<Edge> E;
vector<int> P, R;

bool cmp(const Edge &a, const Edge &b) {
    return a.v < b.v;
}

void init(int n) {
    P.resize(n+1);
    R.resize(n+1);
    for(int i = 0; i <= n; i++) {
        P[i] = i;
        R[i] = 1;
    }
}

int findp(int x) {
    return x == P[x] ? x : P[x] = findp(P[x]);
}

bool joint(int x, int y) {
    x = findp(x), y = findp(y);
    if(x != y) {
        if(R[x] > R[y]) {
            R[x] += R[y];
            P[y] = x;
        } else {
            R[y] += R[x];
            P[x] = y;
        }
        return true;
    }
    return false;
}

int main() {
    int t, n, m, x, y, v;
    cin >> t;
    for (int cases = 1; cases <= t; ++cases) {
        cin >> n >> m;
        E.resize(m);
        for(int i = 0; i < m; i++) {
            cin >> x >> y >> v;
            E[i] = {x, y, v, 0};
        }
        cout << "Case #" << cases << " : ";
        sort(E.begin(), E.end(), cmp);

        int cost = 0;
        vector<int> ontree;
        init(n);
        for(int i = 0; i < m; i++) {
            if(joint(E[i].x, E[i].y)) {
                cost += E[i].v;
                ontree.push_back(i);
            }
        }

        if(ontree.size() != n-1) {
            cout << "No way" << endl;
            continue;
        }

        int mincost = INT_MAX;
        for(int i : ontree) {
            cost = 0;
            E[i].enable = 1;
            init(n);
            int cnt = 0;
            for(int j = 0; j < m; j++) {
                if(!E[j].enable && joint(E[j].x, E[j].y)) {
                    cost += E[j].v;
                    cnt++;
                }
            }
            E[i].enable = 0;
            if(mincost > cost && cnt == n-1)
                mincost = cost;
        }

        if(mincost == INT_MAX)
            cout << "No second way" << endl;
        else
            cout << mincost << endl;
    }
    return 0;
}
