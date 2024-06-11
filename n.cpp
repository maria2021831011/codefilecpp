
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c = 0;
        cin >> n;
        vector<int> a(n), b(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i <= n; i++) {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++) {
            c += abs(a[i] - b[i]);
        }

        int s = abs(a[0] - b[n]);
        for (int i = 0; i < n; i++) {
            s = min(abs(a[i] - b[n]), s);
        }

        cout << c + s + 1 << endl;
    }
    return 0;
}
