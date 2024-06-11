#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter len"<<endl;
    cin>>n;
    int a[n];
        cout<<"array input"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int p,d;
    cout<<"add"<<endl;
    cin>>p;


    cout<<"position="<<endl;
    cin>>d;
    n=n+1;
     for(int i=n-1;i>=d;i--)
     {
         a[i]=a[i-1];
     }

     a[d]=p;

    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }

}
