

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX_VAL = 1e5 + 9;
int vec[35];
int grundy[MAX_VAL];

int Mex(bool vis[]) {
    int mex = 0;
    while (vis[mex])
        mex++;
    return mex;
}
int calculateGrundy(int p, int b) {
    if (p == 0 || p < vec[0])
        return 0;
    if (grundy[p] != -1)
        return grundy[p];

    bool vis[35];
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < b; i++) {
        if (p >= vec[i])
            vis[calculateGrundy(p - vec[i], b)] = true;
    }
    grundy[p] = Mex(vis);

    return grundy[p];
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        memset(grundy, -1, sizeof(grundy));
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < b; i++) {
            cin >> vec[i];
        }
        sort(vec, vec + b);
        int c = 0;
        for (int i = 0; i < a; i++) {
            int h;
            cin >> h;
            c ^= calculateGrundy(h, b);
        }
        if (!c)
            cout << "Vinit" << '\n';
        else
            cout << "Ada" << '\n';
    }
    return 0;
}
