
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int mxN = 1e5 + 5;
int sa[mxN], pos[mxN], tmp[mxN];
int gap, N;
string S;

bool comp(int x, int y) {
    if (pos[x] != pos[y])
        return pos[x] < pos[y];
    x += gap;
    y += gap;
    return (x < N && y < N) ? pos[x] < pos[y] : x > y;
}

void suffix() {
    for (int i = 0; i < N; i++)
        sa[i] = i, pos[i] = S[i];

    for (gap = 1;; gap <<= 1) {
        sort(sa, sa + N, comp);
        for (int i = 0; i < N - 1; i++)
            tmp[i + 1] = tmp[i] + comp(sa[i], sa[i + 1]);
        for (int i = 0; i < N; i++)
            pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1)
            break;
    }
}

int check(int m, const string& x) {
    int f = -1, k = x.size(), j = sa[m];
    if (N - j >= k)
        f = 0;
    for (int i = 0; i < min(N - j, k); i++) {
        if (S[j + i] < x[i])
            return -1;
        if (S[j + i] > x[i])
            return 1;
    }
    return f;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    suffix();

    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int L = 0, R = N - 1;
        int ans = -1, l = L, r = R;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int v = check(m, x);
            if (v == 0) {
                ans = m;
                r = m - 1;
            } else if (v == 1)
                r = m - 1;
            else
                l = m + 1;
        }
        if (ans == -1) {
            cout << 0 << endl;
            continue;
        }
        L = ans, l = L, r = R;
        while (l <= r) {
            int m = l + (r - l) / 2;
            int v = check(m, x);
            if (v == 0) {
                ans = m;
                l = m + 1;
            } else if (v == -1)
                l = m + 1;
            else
                r = m - 1;
        }
        R = ans;
        cout << R - L + 1 << endl;
    }
    return 0;
}
