
#include <iostream>
#include <cmath>
using namespace std;

#define int long long

const int inf = 1LL << 62;
const int md = 1000000007;

struct node {
    int s = 0, z0 = 0, z1 = 0;
};

const int MAXN = 1000005;
node seg[4 * MAXN];

void build(int p, int v, int k, int x, int y) {
    if (x == y) {
        if (x == p) seg[k].s = v;
        return;
    }
    if (x <= p && y >= p) {
        int d = (x + y) / 2;
        build(p, v, 2 * k, x, d);
        build(p, v, 2 * k + 1, d + 1, y);
        seg[k].s = seg[2 * k].s + seg[2 * k + 1].s;
    }
}

void update(int a, int b, int k, int x, int y) {
    if (a > y || b < x) return;
    if (a <= x && b >= y) {
        seg[k].z0 += (1 + x - a);
        seg[k].z1++;
        return;
    }
    int xx = max(a, x), yy = min(b, y);
    seg[k].s += (yy - xx + 1) * (1 + x - min(x, a)) + (yy - xx) * (yy - xx + 1) / 2;
    int d = (x + y) / 2;
    update(a, b, 2 * k, x, d);
    update(a, b, 2 * k + 1, d + 1, y);
}

int sum(int a, int b, int k, int x, int y) {
    if (a > y || b < x) return 0;
    if (a <= x && b >= y) {
        return seg[k].s + seg[k].z0 * (y - x + 1) + seg[k].z1 * (y - x) * (y - x + 1) / 2;
    }
    seg[k].s += seg[k].z0 * (y - x + 1) + seg[k].z1 * (y - x) * (y - x + 1) / 2;
    seg[2 * k].z1 += seg[k].z1, seg[2 * k + 1].z1 += seg[k].z1;
    seg[2 * k].z0 += seg[k].z0;
    seg[2 * k + 1].z0 += (y - x + 1) / 2 * seg[k].z1 + seg[k].z0;
    seg[k].z0 = 0, seg[k].z1 = 0;
    int d = (x + y) / 2;
    return sum(a, b, 2 * k, x, d) + sum(a, b, 2 * k + 1, d + 1, y);
}

signed main() {
    int t = 1;

    for (int i = 1; i <= t; i++) {
        int n, nn, q;
        cin >> n >> q;
        nn = n;
        n = 1 << (int) ceil(log2(n));
        for (int i = 0; i < nn; i++) {
            int x;
            cin >> x;
            build(i, x, 1, 0, n - 1);
        }
        while (q--) {
            int z;
            cin >> z;
            int x, y;
            cin >> x >> y;
            x--, y--;
            if (z == 1)
                update(x, y, 1, 0, n - 1);
            else
                cout << sum(x, y, 1, 0, n - 1) << '\n';
        }
    }
    return 0;
}
