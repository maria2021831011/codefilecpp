
#include<bits/stdc++.h>
using namespace std;

void mergesort();
void merge();
void merge(int arr[],int lb,int mid,int ub)
{
    int n1=mid-lb+1;
    int n2=ub-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++)
    {
        a[i]=arr[lb+i];
    }
    for(int i=0;i<n2;i++)
    {
        b[i]=arr[mid+i+1];
    }

    int i,j,k;
    i=0;
    j=0;
    k=lb;
    while(i<n1&&j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;

        }

    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}


void mergesort(int arr[],int lb,int ub)
{
     int mid;
  if(lb<ub)
  {
   mid=(lb+ub)/2;
   mergesort(arr,lb,mid);
   mergesort(arr,mid+1,ub);
   merge(arr,lb,mid,ub);

  }
}

int main()
{
      int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int lb,ub;
    lb=0;
    ub=n-1;
    mergesort(arr,lb,ub);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }



    return 0;
}
