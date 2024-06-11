#include<bits/stdc++.h>
using namespace std;
void sub(string s)
{
    int p,q;
    cout<<"enter initial and length"<<endl;
    cin>>p>>q;
    string s1[q];
    for(int i=0;i<q;i++)
    {
        s1[i]=s[p-1];
        p++;
    }
    for(int i=0;i<q;i++)
    {
        cout<<s1[i] ;
    }
}
void add(string s)
{
int i,j;
cout<<"The string is:"<<s<<endl;
int r=s.size();
cout<<"Length of the string:"<<r<<endl;
cout<<"enter insert string:"<<endl;
string s1;
cin>>s1;
int p=s1.size();
cout<<"length of the insert string:"<<p<<endl;
int pos;
cout<<"position insert:"<<endl;
cin>>pos;
int t=p+r;
string o;

for(i=r-1;i>=pos-2;i--)
    {
        o[i+p]=s[i];
    }
    for(i=pos-1,j=0;j<p;i++,j++)
    {
        o[i]=s1[j];
    }
    for(i=0;i<pos-1;i++)
    {
        o[i]=s[i];
    }
cout<<"AFTER INSERTION:";
for(int i=0;i<t;i++)
{


cout<<o[i];
}}
void del(string s)
{int m=s.size();
    int p,q;
    cout<<"enter del initial and length"<<endl;
    cin>>p>>q;
    for(int i=0;i<m;i++)
    {
        if(i<(p-1)||i>(p+q-2))
        {
            cout<<s[i];
        }
    }
}
void  rep(string s)
{
    string p1,p2;
    cout<<"enter p1"<<endl;
    cin>>p1;
    cout<<"enter p2"<<endl;
    cin>>p2;
    int t=s.size();
    int len=p1.size();
    int len2=p2.size();
    int i,j;
    i=0;
    bool found=false;
    while(i<t)
    {
    j=0;
    if(s[i]==p1[j])
    {
        int match=i;
        while(j<len&&s[i]==p1[j])
        {
            i++;
            j++;
        }
        if(j==len)
        { s.replace(match,len,p2);
        t=s.size();
            found=true;
        }
    }else{
    i++;}
    }
    if(!found)
    {
        cout<<"enter cantot match"<<endl;
    }
    else
    {for(int i=0;i<t;i++)
    {


        cout<<s[i];
    }
    }
}
    void index(string s)
    {
        string s1;
        cout<<"find dtring"<<endl;
        cin>>s1;
        int p=s.size();
        int l=s1.size();
        int x=0,c=1,i,j;
        for(i=x;s[i]!='\0'&&c!=0;i++)
        {if(s[i]==s1[0])
        {x=i;
        for(j=0;j<l;j++,i++)
     {
       if(s[i]!=s1[j])
       {
           i=x;
           break;

       }
       else if(j+1==l)
       {
           c=0;
           break;
       }
     }   }
        }if(c==0)
        {
            cout<<"index"<<x+1<<endl;
        }else{
        cout<<"cannot match"<<endl;}

        }



int main()
{
    cout<<"1.enter string for sub"<<endl;
    string s;
    cin>>s;
    sub(s);
    cout<<"2.enter add"<<endl;
    add(s);


cout<<"2.enter del"<<endl;
    del(s);

cout<<"2.enter rep"<<endl;
    rep(s);

cout<<"2.enter in"<<endl;
    index(s);

    return 0;
}
