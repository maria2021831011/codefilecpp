
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

struct Query {
    int l, r, index, type;
};

bool compare(Query a, Query b) {
    if ((a.l - 1) / 450 != (b.l - 1) / 450) {
        return (a.l - 1) / 450 < (b.l - 1) / 450;
    }
    return a.r < b.r;
}

int main() {
    int n;
    cin >> n;

    vector<ll> v(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    int m;
    cin >> m;

    vector<Query> queries(m);
    for (int i = 0; i < m; ++i) {
        cin >> queries[i].type >> queries[i].l >> queries[i].r;
        queries[i].index = i;
    }

    sort(queries.begin(), queries.end(), compare);

    ll sum = 0;
    vector<ll> prefixSum(n + 1), sortedPrefixSum(n + 1);
    for (int i = 1; i <= n; ++i) {
        sum += v[i];
        prefixSum[i] = sum;
    }

    sum = 0;
    vector<ll> sortedV(v.begin(), v.end());
    sort(sortedV.begin() + 1, sortedV.end());
    for (int i = 1; i <= n; ++i) {
        sum += sortedV[i];
        sortedPrefixSum[i] = sum;
    }

    int left = 1, right = 0;
    vector<ll> answer(m);

    for (auto q : queries) {
        while (left < q.l) {
            sum -= v[left++];
        }
        while (left > q.l) {
            sum += v[--left];
        }
        while (right < q.r) {
            sum += v[++right];
        }
        while (right > q.r) {
            sum -= v[right--];
        }

        if (q.type == 1) {
            answer[q.index] = sum;
        } else {
            int rangeSize = q.r - q.l + 1;
            ll sortedSum = sortedPrefixSum[q.r];
            if (q.l > 1) {
                sortedSum -= sortedPrefixSum[q.l - 1];
            }
            answer[q.index] = sortedSum;
        }
    }

    for (auto ans : answer) {
        cout << ans << endl;
    }

    return 0;
}
