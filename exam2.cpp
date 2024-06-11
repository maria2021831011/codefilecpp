#include<bits/stdc++.h>
using namespace std;
vector<int>v;
#define ll long long
int main(){ll t;
cin>>t;
while(t--)
{ll c=0;
    ll n;
    cin>>n;
    v.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        c^=v[i];
    }
    if(c)
    {
        cout<<"1"<<endl;
    }else{cout<<"2"<<endl;

}}
}
