
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll x,y,k;
        ll a,b,mx,mn;
        cin>>x>>y>>k;
        if(x%k==0)
        {
            a=x/k;
        }else
        {
            a=x/k +1;
        }

        if(y%k==0)
        {
            b=y/k;
        }else
        {
            b=y/k +1;
        }
        mx=max(a,b);
        mn=min(a,b);
        ll ans=mn+mx+(mx-mn);
        if(a>b)
        {
            ans--;
        }
        cout<<ans<<endl;



    }
}
