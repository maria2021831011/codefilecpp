
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int robin_gold = 0;
    int given_count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= k) {
            robin_gold += a[i];
        } else if (a[i] == 0 && robin_gold > 0) {
            robin_gold--;
            given_count++;
        }
    }

    cout << given_count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
