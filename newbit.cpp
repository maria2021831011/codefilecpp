
#include <bits/stdc++.h>
using namespace std;

const int mx = 10000;
vector<int> tree(mx + 1, 0);

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= i & (-i);
    }
    return sum;
}

void update(int i, int val) {
    while (i <= mx) {
        tree[i] += val;
        i += i & (-i);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> a(n + 1);

    cout << "Enter the elements: ";
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i]);
    }

    int r;
    cout << "Enter the index to query: ";
    cin >> r;
    cout << "Sum of elements up to index " << r << " is: " << query(r) << endl;

    int index, val;
    cout << "Enter index and value to update: ";
    cin >> index >> val;
    update(index, val);

cout << "Sum of elements up to index " << r << " is: " << query(r) << endl;
    return 0;
}
