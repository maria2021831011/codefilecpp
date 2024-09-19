#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(vector<ll>&even,vector<ll>&odd)
{
    ll mx =  odd.back();
ll ans=0;
        for(int i = 0; i < even.size(); i++)
        {
            if(even[i] > mx)
            {
                return(even.size()+1 ) ;

            }
            else
            {
                ans++;
                mx += even[i];
            }
        }
        return ans;
       }


int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;

        vector<ll> even, odd;


        for(int i = 0; i < n; i++)
        {ll a;
            cin >> a;
            if(a % 2 == 0)
            {
                even.push_back(a);
            }
            else
            {
                odd.push_back(a);
            }
        }

        if(even.size()==n||odd.size()==n)
        {
            cout<<"0"<<endl;
            continue;
        }

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        ll ans=f(even,odd);
        cout << ans << endl;

    }
}
