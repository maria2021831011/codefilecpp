#include<bits/stdc++.h>
using namespace std;
int main()
{
    int max;
    cout<<"enter max"<<endl;
    cin>>max;
    int a[max];
    int t;
    cout<<"number insert"<<endl;
    cin>>t;
    int top=-1;
    int i=0;
    while(i<t&&top<max-1)
    {
        int it;
        cout<<"enter ele"<<endl;
        cin>>it;
        top++;
        a[top]=it;
        i++;

    }
    int choice;
    while(true)
    {
        cout<<"1 for pop 2 for push"<<endl;
        cin>>choice;
        switch(choice)
        {
        case 1:
            if(top>=0)
            {
                top--;
            }
            else if(t==0)
            {
                cout<<"cannot"<<endl;
            }
            else if(top==-1)
            {
                cout<<"underflow"<<endl;
            }
            break;
        case 2:
            if(top>max-1)
            {
                int it;
                cin>>it;
                top++;
                a[top]=it;
            }else
            {
                cout<<"overflow"<<endl;
            }break;
            case 3:cout<<"not existing"<<endl;
            break;
            default:cout<<"invalid"<<endl;
        }
        for(int i=0;i<=top;i++)
        {
            cout<<a[i]<< " ";
        }cout<<endl;

    }
}
