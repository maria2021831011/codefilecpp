
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll mx = 200001;
ll v[mx];
ll sum[mx];
ll ans;
ll block = 326; // Adjust the block size accordingly
ll c[1000001]; // Updated to support maximum ai value

struct query {
    ll l, r, i;
};

query q[mx];

// Comparator function for sorting queries based on block and right index
bool compare(query x, query y) {
    if (x.l / block != y.l / block)
        return x.l / block < y.l / block;

    return x.r < y.r;
}

// Function to add an element to the current subarray
void add(int x) {
    ans -= c[x] * c[x] * x;
    c[x]++;
    ans += c[x] * c[x] * x;
}

// Function to remove an element from the current subarray
inline void remove(int x) {
    ans -= c[x] * c[x] * x;
    c[x]--;
    ans += c[x] * c[x] * x;
}

// Function to calculate power of subarrays
void result(ll n, ll v[], ll m) {
    sort(q + 1, q + m + 1, compare); // Sorting queries

    ll cl = 0, cr = -1; // Current left and right indices
    for (int i = 1; i <= m; i++) {
        ll l = q[i].l;
        ll r = q[i].r;

        // Update the current subarray to match the query
        while (cl < l) {
            remove(v[cl]);
            cl++;
        }
        while (cl > l) {
            cl--;
            add(v[cl]);
        }
        while (cr < r) {
            cr++;
            add(v[cr]);
        }
        while (cr > r) {
            remove(v[cr]);
            cr--;
        }

        sum[q[i].i] = ans; // Store the power for this query
    }

    // Output the results for each query
    for (int i = 1; i <= m; i++) {
        cout << sum[i] << endl;
    }
}

int main() {
    ll n, m;
    cin >> n >> m;

    // Read array elements
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Read queries
    for (int i = 1; i <= m; i++) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }

    result(n, v, m); // Calculate and output the power of subarrays
    return 0;
}
