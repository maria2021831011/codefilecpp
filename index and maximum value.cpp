
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define nl cout << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define vi vector<int>
#define PI 3.141592653589793238
#define INF LONG_LONG_MAX
#define MOD 1e9+7
#define show cout << ans << endl

void start() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int32_t main() {
    start();

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;



        int v = INT_MIN;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v = max(v, temp);
        }
        for (int i = 0; i < m; i++) {
            char c;
            int l, r;
            cin >> c >> l >> r;


            if (l <= v && v <= r) {
                if (c == '+') {
                    v = v + 1;
                } else {
                    v = v - 1;
                }
            }


            cout << v;
            if (i != m - 1) {
                cout << " ";
            } else {
                cout << endl;
            }
        }
    }

    return 0;
}


