
#include <bits/stdc++.h>
using namespace std;

const int mx = 10000;
vector<int> tree(mx, 0); // Binary Indexed Tree

// Function to get the sum of elements in range [1, index]
int query(int index) {
    int sum = 0;
    while (index > 0) {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}

// Function to update the BIT at given index with given value
void update(int index, int value) {
    while (index <= mx) {
        tree[index] += value;
        index += index & (-index);
    }
}

int main() {
    int n;
    cin >> n;


    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        update(i, num);
    }


    cout << query(5) << endl;
    update(3, 5);
    update(2, 5);
    cout << query(2) << endl;

    return 0;
}
