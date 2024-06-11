
#include <bits/stdc++.h>

using namespace std;
typedef array<int, 3> triple;
const int maxN = 2e5 + 1;

int n,q, a, b;
vector<int> x(maxN), p(maxN), d(maxN), ans(maxN);
vector<triple> queries(maxN);
map<int, int> mp;
set<int> S;

void update(int idx, int val) {
    for (int i = idx; i <= n; i += -i & i)
        d[i] += val;
}

int query(int idx) {
    int sum = 0;
    for (int i = idx; i > 0; i -= -i & i)
        sum += d[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n>>q;
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    for (int i = n; i > 0; i--) {
        if (mp[x[i]])
            p[i] = mp[x[i]];
        mp[x[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        if (S.count(x[i]) == 0)
            update(i, 1);
        S.insert(x[i]);
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        queries[i] = {a, b, i};
    }
    sort(queries.begin(), queries.begin() + q);

    int l = 1;
    for (int i = 0; i< q; i++) {
        while (l < queries[i][0]) {
            if (p[l])
                update(p[l], 1);
            l++;
        }
        ans[queries[i][2]] = query(queries[i][1]) - query(queries[i][0] - 1);
    }

    for (int i= 0; i< q; i++)
        cout << ans[i] << '\n';

    return 0;
}
