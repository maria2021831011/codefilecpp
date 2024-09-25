#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n, k;
    cin >> n >> k;
    long long start = n - k + 1;
    long long odd_start = (start % 2 == 1) ? start : start + 1;
    long long odd_end = (n % 2 == 1) ? n : n - 1;

    long long odd_count = (odd_end >= odd_start) ? (odd_end - odd_start) / 2 + 1 : 0;

    if (odd_count % 2 == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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
