
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int k = 10000005;
bitset<k> p;
vector<ll> primes;
void sieve() {
    p[0] = p[1] = true;
    for (int i = 4; i < k; i += 2) p[i] = true;
    primes.push_back(2);

    int limit = sqrt(k) + 1;
    for (int i = 3; i < k; i += 2) {
        if (!p[i]) {
            primes.push_back(i);
            if (i <= limit) {
                for (int j = i * i; j < k; j += i) {
                    p[j] = true;
                }
            }
        }
    }
}

int main() {
    sieve();
    ll t;
    cin >> t;
    for (ll c= 1; c <= t; ++c) {
        cout << "Case " << c<< ": ";
        ll n;
        cin >> n;
        ll count = 0;
        for (ll i = 0; primes[i] <= n / 2; ++i) {
            ll u = n - primes[i];
            if (!p[u]) {
                count++;
            }
        }

        cout << count << '\n';
    }

    return 0;
}
