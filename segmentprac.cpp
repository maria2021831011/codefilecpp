#include <bits/stdc++.h>
using namespace std;
vector<long long> bit1(100002), bit2(100002);
void update(vector<long long> &bit, int idx, long long val) {
    for (int x = idx; x <= 100001; x += x & -x)
        bit[x] += val;
}
long long query(vector<long long> &bit, int idx) {
    long long ret = 0;
    for (int x = idx; x > 0; x -= x & -x)
        ret += bit[x];

    return ret;
}

int main() {
    int T, N, Q;
    cin >> T;

    while (T--) {
        cin >> N >> Q;
        bit1.assign(100002, 0);
        bit2.assign(100002, 0);
        for (int i = 0; i < Q; ++i) {
            int op, l, r, v;
            cin >> op >> l >> r;

            if (op == 0) {
                cin >> v;
                update(bit1, l, v);
                update(bit1, r + 1, -v);
                update(bit2, l, -(long long)v * (l - 1));
                update(bit2, r + 1, (long long)v * r);
            } else {
                cout << query(bit1, r) * r + query(bit2, r) - query(bit1, l - 1) * (l - 1) - query(bit2, l - 1) << '\n';
            }
        }
    }

    return 0;
}
