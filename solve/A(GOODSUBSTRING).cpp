#include<bits/stdc++.h>
using namespace std;
struct node
{
    node* link[26];
};
int main()
{
   string s,gb;
   cin>>s>>gb;

   int t;
   cin>>t;
   node* head=new node();
   int ans=0;
   for(int i=0;i<s.size();i++)
   {
       int cb=0;
       node* cnode=head;
       for(int j=i;j<s.size();j++)
       {
           int c=s[j]-'a';
           if(gb[c]=='0')cb++;
           if(cb>t)break;
           if(cnode->link[c]==NULL)
           {
               cnode->link[c]=new node();
               ans++;
           }cnode=cnode->link[c];
       }
   }cout<<ans<<endl;
}
