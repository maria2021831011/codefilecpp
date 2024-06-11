#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  n,pos=0;
    cout<<"enter string length"<<endl;
    cin>>n;
    string s;
    cout<<"enter string"<<endl;
    cin>>s;
    char p;
    cout<<"enter value"<<endl;
    cin>>p;
    int e=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==p)
        {


        pos=i;
        e=1;
    }
    }
    if(e==0)




    {cout<<"erro"<<endl;}

    else{
      cout<<pos<<endl;
    }
}
