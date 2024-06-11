#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,t;
    cin>>m;
    cin>>t;
    int a[m];
    int front=-1;
    int rear=-1;
    int i=0;
    while(i<t)
    {
        int it;
        cin>>it;
        if((front==0 &&rear==m-1)||(rear+1==front))
        {
            cout<<"full"<<endl;
        }else
        {
            if(front==-1)
            {
                front=0;
            }if(rear=m-1)
            {
                rear=0;
            }else
            {
                rear++;
            }
            a[rear]=it;
            i++;
        }
    }
    int ch;
    while(true)
    {
        cin>>ch;
        switch(ch)
        {
        case 1:
            if(front==-1)
            {
                cout<<"underflow"<<endl;
            }else
            {
                if(front==rear)
                {
                    front=-1;
                    rear=-1;
                }else if(front==m-1)
                {
                    front=0;
                }else
                {
                    front++;
                }
            }break;
            case 2:
                if((front==0 && rear==m-1)||(rear+1==front))
        {
            cout<<"overflow"<<endl;
        }else
        {int it;
        cin>>it;
            if(front==-1)
            {
                front=0;
            }if(rear=m-1)
            {
                rear=0;
            }else
            {
                rear++;
            }
            a[rear]=it;
            i++;
        }
        break;
        case 3:cout<<"not esisting"<<endl;
        break;
        default:cout<<"invalid"<<endl;
        }
        if(front==-1)
{
    cout<<"empty"<<endl;

}   else if(front<=rear){
    for(int i=front;i<=rear;i++)
    {
        cout<<a[i]<<" ";
    }cout<<endl;


    }
    else
    {
        for(int i=0;i<=rear;i++)
        {
            cout<<a[i]<<" ";
        }cout<<endl;
        for(int i=front;i<=m;i++)
        {
            cout<<a[i]<<" ";
        }cout<<endl;
    }
        }
    }

