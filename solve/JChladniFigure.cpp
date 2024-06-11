

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
        a.push_back({a[i].second, a[i].first});
    }
    m <<= 1;

    sort(a.begin(), a.end(), [=](pair<int, int>& a, pair<int, int>& b) {
        if (a.first != b.first)
            return a.first < b.first;
        return (a.second + n - a.first) % n < (b.second + n - b.first) % n;
    });

    vector<int> s;
    for (int j, i = 0; i < m; i = j) {
        for (j = i; j < m && a[j].first == a[i].first; ++j)
            s.push_back((a[j].second + n - a[i].first) % n);
        s.push_back(-(j == m ? a[0].first + n - a[i].first : a[j].first - a[i].first));
    }

    m = s.size();
    vector<int> next(m);
    for (int j, i = 1; i < m; ++i) {
        for (j = next[i - 1]; j > 0 && s[j] != s[i]; j = next[j - 1]);
        next[i] = j + (s[i] == s[j]);
    }

    auto t = s;
    for (int i = 0; i < m; ++i)
        t.push_back(t[i]);

    int i = 1, j = 0;
    for (; i < m * 2 - 1 && j < m; ) {
        if (t[i] == s[j])
            ++i, ++j;
        else if (j == 0)
            ++i;
        else
            j = next[j - 1];
    }
    cout << (j == m ? "YES" : "NO") << endl;
    return 0;
}
