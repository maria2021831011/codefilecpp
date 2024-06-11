#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> cost(n + 1, 0);
    vector<bool> check(n + 1, false);

    for(int i = 1; i <= n; ++i)
        cin >> cost[i];

    cin >> m;
    long long total = 0;
    int childs = 0;

    for(int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;

        if (!check[b]) {
            childs++;
            total += c;
            cost[b] = c;
            check[b] = true;
        } else {
            if (cost[b] > c) {
                total = total - cost[b] + c;
                cost[b] = c;
            }
        }
    }

    if (childs == n - 1)
        cout << total << endl;
    else
        cout << -1 << endl;

    return 0;
}
