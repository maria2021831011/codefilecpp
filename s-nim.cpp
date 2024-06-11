#include<bits/stdc++.h>
using namespace std;

int mex(unordered_set<int> s) {
    int mex = 0;
    while (s.find(mex) != s.end())
        mex++;
    return mex;
}

int findgrundy(int n, int g[]) {
    g[0]=0;
    g[1]=1;
    g[2]=2;
    g[3]=3;
    unordered_set<int> set;
    if (g[n] != -1)
        return g[n];
    for (int i = 1; i <= 3; i++)
        set.insert(findgrundy(n - i, g));
    g[n] = mex(set);
    return g[n];
}

void winner(int t, vector<int>& v, int g[], int n) {
    int xor_sum = g[v[0]];
    for (int i = 1; i < n; i++) {
        xor_sum ^= g[v[i]];
    }
    if (xor_sum != 0) {
        if (t == 1) {
            cout << "1st player" << endl;
        } else {
            cout << "2nd player" << endl;
        }
    } else {
        if (t == 1) {
            cout << "2nd player" << endl;
        } else {
            cout << "1st player" << endl;
        }
    }
}

int main() {
    int n, t;
    cin >> n >> t; // 1 for player 1, 2 for player 2
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int maximum = *max_element(v.begin(), v.end());
    int g[maximum + 1];
    memset(g, -1, sizeof(g));
    for (int i = 0; i < n; i++) {
        findgrundy(v[i], g);
    }
    winner(t, v, g, n);
    return 0;
}
