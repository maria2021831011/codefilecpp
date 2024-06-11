
#include <bits/stdc++.h>
using namespace std;
const int N = 250;
char s[N];
int p[N];
bool st[250];
unsigned long long gcd(unsigned long long a, unsigned long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> (s + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        memset(st, false, sizeof(st));
        unsigned long long res = 1;
        for (int i = 1; i <= n; i++) {
            if (st[i]) continue;

            vector<int> a;
            a.push_back(i);
            int u = p[i];
            while (u != i) {
                a.push_back(u);
                st[u] = true;
                u = p[u];
            }
            map<int, int> mp;
            for (int j = 0; j < a.size(); j++) {
                int cnt = 1;
                int u = a[j];
                char c = s[u];
                while (cnt <= a.size()) {
                    u = p[u];
                    if (s[u] == c)
                        mp[cnt]++;
                    cnt++;
                }
            }
            for (auto v : mp) {
                if (v.second == a.size()) {
                    res = res / gcd(res, (unsigned long long)v.first) * (unsigned long long)v.first;
                    break;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
