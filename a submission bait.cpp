#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int c=1;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        map<int,int>m;
        for(auto i:a)
        {
            m[i]++;
        }
        for(auto it:m)
        {
            if(it.second%2!=0)
            {
                c=0;
                break;
            }
            }if(c==1)
            cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
        }
}

