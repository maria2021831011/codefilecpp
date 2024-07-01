
#include <bits/stdc++.h>
using namespace std;

const int k = 3001;
bool prime[k];

void sieve() {
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < k; i++) {
        if (prime[i]) {
            for (int j = i * i; j < k; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    int n;
    cin >> n;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        int f = 0;
        for (int j = 2; j <= i; j++) {
            if (prime[j] && i % j == 0) {
                f++;
            }
        }
        if (f == 2) {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}
