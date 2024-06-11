
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<ll> longestprefixsuffix(string B)
{
    ll m = B.length();
    vector<ll> lps(m);
    lps[0] = 0;
    ll i = 1;
    ll len = 0;

    while (i < m) {
        if (B[i] == B[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {if(len!=0){
                len = lps[len - 1];}
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps; }
vector<ll> KMP(string A, string B)
{
    ll n = A.length();
    ll m = B.length();
    vector<ll> lps = longestprefixsuffix(B);

    ll i = 0;
    ll j = 0;
    vector<ll> v1;
    while (i < n) {
        if (A[i] == B[j]) {

            i++;
            j++;
        }
        if (j == m)
        {
            v1.push_back(i - j + 1);
            j = lps[j - 1];
        }

        else if (i < n and A[i] != B[j]) {

            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return v1;
}

int main()
{
    ll t;
    cin >> t;

    while (t--) {
        string A, B;
        cin >> A >> B;

        vector<ll> v1 = KMP(A, B);
        if (v1.size() != 0) {
            cout << v1.size() << "\n";
            for (auto it = v1.begin(); it != v1.end(); it++) {
                cout << *it << " ";
            }
        }
        else
            cout << "Not Found";
        cout << "\n";
    }

    return 0;
}
