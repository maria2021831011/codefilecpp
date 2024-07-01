#include <bits/stdc++.h>
using namespace std;


struct Query {
    int l, r, i;
};

int block;
int v[30001];
int ans[200001];
int freq[1000001];
Query q[200001];
bool compare(Query x, Query y) {
    if (x.l / block != y.l / block)
        return x.l / block < y.l / block;
    return x.r < y.r;
}

void queryResults(int v[], int n, Query q[], int m) {
    block = (int)sqrt(n);
    sort(q, q + m, compare);

    int currL = 0, currR = 0;
    int uniqueCount = 0;

    for (int i = 0; i < m; i++) {
        int L = q[i].l, R = q[i].r;

        while (currL < L) {
            if (--freq[v[currL]] == 0) uniqueCount--;
            currL++;
        }
        while (currL > L) {
            if (++freq[v[currL - 1]] == 1) uniqueCount++;
            currL--;
        }
        while (currR <= R) {
            if (++freq[v[currR]] == 1) uniqueCount++;
            currR++;
        }
        while (currR > R + 1) {
            if (--freq[v[currR - 1]] == 0) uniqueCount--;
            currR--;
        }

        ans[q[i].i] = uniqueCount;
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << endl;
    }
}

int main() {
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
cin>>m;

    for (int i = 0; i < m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }
    queryResults(v, n, q, m);
    return 0;
}
