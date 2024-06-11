
#include <bits/stdc++.h>

using namespace std;
bool hasPeriod(const string& s, int k) {
    int n = s.size();
    if (n % k != 0) return false;

    for (int i = k; i < n; i++) {
        if (s[i] != s[i % k]) return false;
    }

    return true;
}


int smallestPeriod(const string& s) {
    int n = s.size();

    for (int k = 1; k <= n / 2; k++) {
        if (hasPeriod(s, k)) return k;
    }

    return n;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int period = smallestPeriod(s);
        cout << period << endl;
    }

    return 0;
}
