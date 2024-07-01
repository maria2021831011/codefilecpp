
#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e7;
typedef unsigned long long ull;

vector<int> min_prime(MAX, 0);
vector<bool> is_prime(MAX, true);
vector<ull> fibo_sum(MAX, 0);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i; j < MAX; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
                is_prime[j] = false;
            }
        }
    }
}

void precompute() {
    sieve();
    ull sum = 0;
    for (int i = 0; i < MAX; ++i) {
        sum += min_prime[i];
        fibo_sum[i] = sum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    precompute();

    int t, a;
    cin >> t;
    while (t--) {
        cin >> a;
        cout << fibo_sum[a] << endl;
    }

    return 0;
}
