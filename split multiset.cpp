
#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{int n,k;
cin>>n>>k;
if(n==1)
{
    cout<<"0"<<endl;
    return;
}
n-=k;
int ans=1;
ans+=max(0ll,(ll)ceil(n*1.0/(k-1)));
 cout<<ans<<endl;


}
int main()
{
    int t;
    cin>>t;
    while(t--)
    { solve();
    }
}
