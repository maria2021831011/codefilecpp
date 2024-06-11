#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200100;
long long t[MAX_N * 4], lazy[MAX_N * 4], a[MAX_N], n, q;

void build(int id = 1, int l = 1, int r = n) {
    if (l == r)
        t[id] = a[l];
    else {
        int mid = (l + r) >> 1;
        build(id << 1, l, mid);
        build(id << 1 | 1, mid + 1, r);
        t[id] = t[id << 1] + t[id << 1 | 1];
    }
}

void push(int id, int l, int r) {
    if (lazy[id]) {
        t[id] += ((r - l + 1) * (2 * lazy[id] + r - l)) / 2;
        if (l != r) {
            lazy[id << 1] += lazy[id];
            lazy[id << 1 | 1] += lazy[id] + (l + r) / 2 - l + 1;
        }
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (l > rq || r < lq)
        return;
    if (lq <= l && r <= rq) {
        lazy[id] = l - lq + 1;
        push(id, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, lq, rq);
    update(id << 1 | 1, mid + 1, r, lq, rq);
    t[id] = t[id << 1] + t[id << 1 | 1];
}

long long query(int id, int l, int r, int lq, int rq) {
    push(id, l, r);
    if (l > rq || r < lq)
        return 0;
    if (lq <= l && r <= rq)
        return t[id];
    int mid = (l + r) >> 1;
    return query(id << 1, l, mid, lq, rq) + query(id << 1 | 1, mid + 1, r, lq, rq);
}

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(1, 1, n, l, r);
        else
            cout << query(1, 1, n, l, r) << '\n';
    }
    return 0;
}
