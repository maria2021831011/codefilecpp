
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int s = 200005;
const int S = 1e6 + 100;
int block, n, m;
int l, r, x;
int a[s], mp[S];
ll ans[s], sum;

struct query {
    int l, r, idx;
} q[s];

bool cmp(query a, query b) {
    if (a.l / block != b.l / block)
        return a.l < b.l;

    return a.r < b.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    block = 450;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        q[i].l = l - 1;
        q[i].r = r;
        q[i].idx = i;
    }

    sort(q, q + m, cmp);

    int cl, cr;
    int pl, pr;


    pl = 0;
    pr = 0;
    sum = 0;
    for (int i = 0; i < m; i++) {
        cl = q[i].l;
        cr = q[i].r;


        while (pl > cl) {
            pl--;
            x = a[pl];

            sum -= (ll)mp[x] * mp[x] * x;
            mp[x]++;
            sum += (ll)mp[x] * mp[x] * x;
        }
        while (pl < cl) {
            x = a[pl];

            sum -= (ll)mp[x] * mp[x] * x;
            mp[x]--;
            sum += (ll)mp[x] * mp[x] * x;

            pl++;
        }

        while (pr < cr) {
            x = a[pr];

            sum -= (ll)mp[x] * mp[x] * x;
            mp[x]++;

            sum += (ll)mp[x] * mp[x] * x;

            pr++;
        }
        while (pr > cr) {
            pr--;
            x = a[pr];

            sum -= (ll)mp[x] * mp[x] * x;
            mp[x]--;

            sum += (ll)mp[x] * mp[x] * x;
        }

        ans[q[i].idx] = sum;
    }

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";


}
