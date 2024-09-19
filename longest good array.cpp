#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n1, n2;
        cin >> n1 >> n2;
        ll diff = n2 - n1;
        ll m = (ll)((-1 + sqrt(1 + 8 * diff)) / 2);

        cout << m << endl;
    }
    return 0;
}
