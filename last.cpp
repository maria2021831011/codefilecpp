#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()

{ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int n;
    cin>>n;
    v.resize(n);
int    sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        sum^=v[i];
    }if(sum)
    {
        cout<<"1"<<endl;
    }else
    {
        cout<<"2"<<endl;
    }
}
