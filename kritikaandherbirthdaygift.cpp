#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

const int MAXN = 1000001;


struct Query {
    int l, r, idx;
};

int block;
int freq[MAXN];
Query q[MAXN];
int ans[1000001];

bool compare(Query a, Query b) {
    if (a.l / block != b.l / block)
        return a.l / block < b.l / block;
    return a.r < b.r;
}

void add(int pos) {
    freq[pos]++;
}

void remove(int pos) {
    freq[pos]--;
}

int main() {
    int n;
    cin >> n;

    string s[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r >> q[i].idx;
        q[i].l--; // Convert to 0-based indexing
        q[i].r--; // Convert to 0-based indexing
        q[i].idx--; // Convert to 0-based indexing
    }

    block = (int)sqrt(n); // Size of each block

    sort(q, q + m, compare);

    int curL = 0, curR = -1;

    for (int i = 0; i < m; i++) {
        int left = q[i].l;
        int right = q[i].r;

        while (curL > left) {
            curL--;
            add(freq[curL]);
        }
        while (curR < right) {
            curR++;
            add(freq[curR]);
        }
        while (curL < left) {
            remove(freq[curL]);
            curL++;
        }
        while (curR > right) {
            remove(freq[curR]);
            curR--;
        }

        ans[q[i].idx] = freq[q[i].r + 1] - freq[q[i].l]; // freq[r+1] - freq[l] gives count of S between l and r
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
