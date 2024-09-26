#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define Block 1000
#define nl cout << endl
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define vi vector<int>
#define basic int n; cin >> n; vi a(n); for(int i = 0; i < n; i++) cin >> a[i]
#define PI 3.141592653589793238;
#define INF LONG_LONG_MAX;
#define MOD 1e9+7;
#define show cout << ans << endl

void start() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int fact(int n) {
    if(n == 1) return 1;
    return (n * fact(n - 1));
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

bool checkPrime(int n) {
    int cnt = 0;
    for(int i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            cnt++;
            if((n / i) != i)
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

bool check(vector<int>& v1, vector<int>& v2, vector<int>& v3, int x, string p) {
    int k = v1.size();
    int temp = 0;
    int la = 0, ra = -1, lb = -1, rb = -1, lc = -1, rc = -1;

    for(int i = 0; i < k; i++) {
        temp += v1[i];
        if(temp >= x) {
            ra = i;
            break;
        }
    }
    temp = 0;
    if(ra > k - 3) return false;
    lb = ra + 1;

    for(int i = lb; i < k; i++) {
        temp += v2[i];
        if(temp >= x) {
            rb = i;
            break;
        }
    }
    temp = 0;
    if(rb > k - 2) return false;
    lc = rb + 1;

    for(int i = lc; i < k; i++) {
        temp += v3[i];
        if(temp >= x) {
            rc = i;
            break;
        }
    }

    if(rc > k - 1 || lc > k - 1) return false;
    if(la < 0 || ra < 0 || lb < 0 || rb < 0 || lc < 0 || rc < 0) return false;
    la++; ra++; lb++; rb++; lc++; rc++;

    if(p == "v1v2v3") cout << la << " " << ra << " " << lb << " " << rb << " " << lc << " " << rc << endl;
    if(p == "v2v1v3") cout << lb << " " << rb << " " << la << " " << ra << " " << lc << " " << rc << endl;
    if(p == "v1v3v2") cout << la << " " << ra << " " << lc << " " << rc << " " << lb << " " << rb << endl;
    if(p == "v3v2v1") cout << lc << " " << rc << " " << lb << " " << rb << " " << la << " " << ra << endl;
    if(p == "v2v3v1") cout << lc << " " << rc << " " << la << " " << ra << " " << lb << " " << rb << endl;
    if(p == "v3v1v2") cout << lb << " " << rb << " " << lc << " " << rc << " " << la << " " << ra << endl;

    return true;
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> v1(n), v2(n), v3(n);
    for(int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v2[i];
        sum += v2[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> v3[i];
    }

    // Fix the calculation of x to avoid truncation issues
    int x = ceil((double)sum / 3);

    if(check(v1, v2, v3, x, "v1v2v3")) return;
    if(check(v2, v1, v3, x, "v2v1v3")) return;
    if(check(v1, v3, v2, x, "v1v3v2")) return;
    if(check(v3, v2, v1, x, "v3v2v1")) return;
    if(check(v2, v3, v1, x, "v2v3v1")) return;
    if(check(v3, v1, v2, x, "v3v1v2")) return;

    cout << -1 << endl;
}

int32_t main() {
    start();
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}

