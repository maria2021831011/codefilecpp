
#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 100005;

struct Node {
    int gcd;
    int count;
};

int arr[MAX_N];
Node tree[4 * MAX_N];

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void build(int node, int start, int end) {
    if (start == end) {
        tree[node].gcd = arr[start];
        tree[node].count = 1;
    } else {
        int mid = (start + end) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node].gcd = gcd(tree[2 * node].gcd, tree[2 * node + 1].gcd);
        tree[node].count = 0;
        if (tree[node].gcd == tree[2 * node].gcd)
            tree[node].count += tree[2 * node].count;
        if (tree[node].gcd == tree[2 * node + 1].gcd)
            tree[node].count += tree[2 * node + 1].count;
    }
}

Node query(int node, int start, int end, int l, int r) {
    if (r < start || end < l)
        return {0, 0};
    if (l <= start && end <= r)
        return tree[node];
    int mid = (start + end) / 2;
    Node left = query(2 * node, start, mid, l, r);
    Node right = query(2 * node + 1, mid + 1, end, l, r);
    Node result;
    result.gcd = gcd(left.gcd, right.gcd);
    result.count = 0;
    if (result.gcd == left.gcd)
        result.count += left.count;
    if (result.gcd == right.gcd)
        result.count += right.count;
    return result;
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    build(1, 1, n);
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        Node result = query(1, 1, n, l, r);
        cout << r - l + 1 - result.count << endl;
    }
    return 0;
}
