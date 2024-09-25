#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define nl cout<<endl
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define vi vector<int>
#define PI 3.141592653589793238
#define INF LONG_LONG_MAX
#define MOD 1e9+7
#define show cout<<ans<<endl

void start() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}



void m() {
    string a;
    cin >> a;
    bool found = false;

    if (a.size() % 2 == 0) {
        for (int i = 1; i < a.size() / 2; i++) {
            if (a[0] == a[i]) {
                int j = 0;
                while ((i + j) < a.size() && a[j] == a[i + j]) {
                    j++;
                }
                if (i + j == a.size()) {
                    yes;
                    for (int k = i; k < a.size(); k++) {
                        cout << a[k];
        }nl;
                    return;
                }
            }
        }
        no;
    } else {
        for (int i = 1; i <= a.size() / 2; i++) {
            if (a[0] == a[i]) {
                int j = 0;
                while ((i + j) < a.size() && a[j] == a[i + j]) {
                    j++;
                }
                if (i + j == a.size()) {
                    yes;
                    for (int k = i; k < a.size(); k++) {
                        cout << a[k];
                    }
                    nl;
                    return;
                }
            }
        }
        no;
    }
}
int32_t main() {
    start();

    int tc;
    tc = 1;
    while (tc--) {
        m();
    }
}
