#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,a,b;
        cin>>x>>y>>a>>b;
        int ans=0;
        if((x>a&&y>=b)||(x>=a&&y>b))
            ans+=2;
        if((y>=a&&x>b)||(x>=b&&y>a))
            ans+=2;
        cout<<ans<<endl;
    }
}
