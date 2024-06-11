
#include<bits/stdc++.h>
#define ll long long
#define mode 10^9+7
using namespace std;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,sum=0,ans=0,m=0;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            m+=v[i];
sum+=v[i];
if(sum<0)
{
    sum=0;
}
m=((m-ans)%mod+mod)%mod;
ans%=mod;
cout<<(m%mod+((powermod(2,k,mod) %mod*ans%mod)%mod)%mod)%mod<<endl;
}
}
