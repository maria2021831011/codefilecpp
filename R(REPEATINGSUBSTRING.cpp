
#include<bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 5;
int sa[mxN], pos[mxN], tmp[mxN], lcp[mxN];
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

void build_lcp() {
    for (int i = 0, k = 0; i < N; i++) if (pos[i] != N - 1) {
        int j = sa[pos[i] + 1];
        while (S[i + k] == S[j + k])
            k++;
        lcp[pos[i]] = k;
        if (k) k--;
    }
}

int main() {
    cin >> S;
    N = S.size();
    suffix();
    build_lcp();
    int mx = max_element(lcp, lcp + N) - lcp;
    if (lcp[mx] == 0)
        cout << -1;
    else
        cout << S.substr(sa[mx], lcp[mx]);
    return 0;
}
