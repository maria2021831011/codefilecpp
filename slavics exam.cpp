#include<bits/stdc++.h>
using namespace std;
void cas()
{
    string s,t;
    cin>>s;
    cin>>t;
    int l=0;
    for(int i=0;i<s.size()&&l<t.size();i++)
    {
        if(s[i]==t[l]){l++;}
        else if(s[i]=='?')
        {s[i]=t[l];
        l++;}
    }
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='?')s[i]='a';
    }
    if(l==t.size())
    {
        cout<<"YES"<<endl;
        cout<<s<<endl;
    }else{cout<<"NO"<<endl;}

    }
int main()
{
    int t ;
    cin>>t;
    while(t--)
    {
        cas();
    }
}
