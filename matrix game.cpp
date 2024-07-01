
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n, m;
        cin >> n >> m;
        ll xor_sum = 0;

        for (int i = 0; i < n; ++i) {
            ll row_sum = 0;
            for (int j = 0; j < m; ++j) {
                int a;
                cin >> a;
                row_sum += a;
            }
            xor_sum ^= row_sum; // Calculate XOR of row sums
        }

        cout << "Case " << tc << ": ";
        if (xor_sum > 0)
            cout << "Alice" << "\n";
        else
            cout << "Bob" << "\n";
    }

    return 0;
}
