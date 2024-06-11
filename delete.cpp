#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,pos=0;
    cout<<"enter array number"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p;
    cout<<"delete data"<<endl;
    cin>>p;

    for(int i=0;i<n;i++)
    {
        if(a[i]==p)
        {
            pos=i;
        }
    }

    for(int i=pos+1;i<n;i++)
    {
        a[i-1]=a[i];
    }
    n=n-1;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;


}
