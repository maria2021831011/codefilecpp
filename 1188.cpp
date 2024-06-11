#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

int tree[3 * 100008];
int mark[100008];
int ans[100008];
int n, q;

class nod {
public:
    int type, x, y, s;
};


bool cmp(nod a, nod b) {
    if (a.y != b.y)
        return a.y < b.y;

    return a.type < b.type;
}

int build(int nod, int l, int r, int c, int v) {
    if (l > c || r < c) return tree[nod];
    if (l == r && c == r)
        return tree[nod] = v;

    int mid = (l + r) >> 1;

    int left = 2 * nod;
    int right = 2 * nod + 1;

    return tree[nod] = build(left, l, mid, c, v) + build(right, mid + 1, r, c, v);
}

int query(int nod, int l, int r, int i, int j) {
    if (i > r || j < l) return 0;

    if (i <= l && j >= r) return tree[nod];

    int mid = (l + r) >> 1;

    int left = 2 * nod;
    int right = 2 * nod + 1;

    return query(left, l, mid, i, j) + query(right, mid + 1, r, i, j);
}

int main() {
    int t, tcase = 1;
    cin >> t;

    while (t--) {
        cin >> n >> q;

        fill(tree, tree + 3 * 100008, 0);
        fill(mark, mark + 100008, -1);

        nod kp[150008];

        for (int i = 0; i < n; i++) {
            kp[i].type = 1;
            cin >> kp[i].x;
            kp[i].y = i;
        }

        for (int i = n, j = 0; i < n + q; i++, j++) {
            kp[i].type = 2;
            cin >> kp[i].x >> kp[i].y;
            kp[i].x--;
            kp[i].y--;
            kp[i].s = j;
        }

        sort(kp, kp + n + q, cmp);

        cout << "Case " << tcase++ << ":" << endl;

        for (int i = 0; i < n + q; i++) {
            if (kp[i].type == 1) {
                if (mark[kp[i].x] != -1) {
                    build(1, 0, n, mark[kp[i].x], 0);
                }

                mark[kp[i].x] = kp[i].y;
                build(1, 0, n, mark[kp[i].x], 1);
            } else {
                ans[kp[i].s] = query(1, 0, n, kp[i].x, kp[i].y);
            }
        }

        for (int i = 0; i < q; i++)
            cout << ans[i] << endl;
    }

    return 0;
}
