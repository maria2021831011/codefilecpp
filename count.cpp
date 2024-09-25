#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define Block 1000
#define nl cout<<endl
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vi vector<int>
#define basic int n;cin>>n; vi a(n); for(int i=0;i<n;i++)cin>>a[i]
#define PI 3.141592653589793238
#define INF LONG_LONG_MAX
#define MOD 1e9+7
#define show cout<<ans<<endl

void start() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int fact(int n) {
    if (n == 1) return 1;
    return (n * fact(n - 1));
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool checkPrime(int n) {
    int cnt = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if ((n / i) != i)
                cnt++;
        }
    }
    return cnt == 2;
}

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

int32_t main() {
    start();

    int T = 1;
    cin >> T;
    while (T--) {
        set<pair<int, int>> s;
        int n;
        cin >> n;
        int k, p;
        for (int i = 0; i < n; i++) {
            cin >> k >> p;
            s.insert({k, p});
        }

        int s1 = 0, s2 = 0;
        for (auto z : s) {
            k = z.first;
            p = z.second;
            if (s.find({k, 1 - p}) != s.end()) {
                s1 = n - 2;
            }
            if (s.find({k - 1, 1 - p}) != s.end() && s.find({k + 1, 1 - p}) != s.end())
                s2++;
        }

        int ans = s1 + s2;
        show;
    }

    return 0;
}

