
//BINARY SEARCH CODE
#include<bits\stdc++.h>
using namespace std;

int main()
{    cout<<"enter array size :"<<endl;
    int n;
    cin>>n;
    char s[n];
    cout<<" enter character array element :"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
sort(s,s+n);

     char c;
     int d=0;
     cout<<"Enter the character"<<endl;
    cin>>c;;
     int lb=0;
     int ub=n-1;
     int mid;
     while(lb<=ub)
     {
          mid=(lb+ub)/2;

        if(s[mid]<c)
          {
              lb=mid+1;
          }
          else if(s[mid]>c)
          {
              ub=mid-1;
          }

          if(s[mid]==c)
          {
        cout<<"Data found at index:"<<mid;
            d=1;
            break;
          }
     }
     if(d==0)
     {
         cout<<"Data not found.";
     }

    return 0;
}
