
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int sons[2] = {0};
    int cnt = 0;
};
const int kk = 3e6;
Node nodes[kk];
int p = 0;

void add(int x, int val) {
    int id = 0;
    for (int i = 30; i >= 0; --i) {
        nodes[id].cnt += val;
        bool bit = (x & (1 << i)) > 0;
        if (!nodes[id].sons[bit])
            nodes[id].sons[bit] = ++p;
        id = nodes[id].sons[bit];
    }
    nodes[id].cnt += val;
}

int getmax(int x) {
    int id = 0;
    int ans = 0;
    for (int i = 30; i >= 0; --i) {
        bool bit = (x & (1 << i)) > 0;
        bit ^= true;
        if (nodes[id].sons[bit] && nodes[nodes[id].sons[bit]].cnt)
            ans += (1 << i), id = nodes[id].sons[bit];
        else
            id = nodes[id].sons[bit ^ true];
    }
    return ans;
}

int main() {
    add(0, 1);
    int q;
    cin >> q;
    while (q--) {
        char type;
        int x;
        cin >> type >> x;
        if (type == '+')
            add(x, 1);
        else if (type == '-')
            add(x, -1);
        else if (type == '?')
            cout << getmax(x) << '\n';
    }
    return 0;
}
