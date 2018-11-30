#include<iostream>

using namespace std;

void merge(int a[],int l,int mid, int h)
{
    int i = l, j = mid, k=0;
    int b[h-l];

    while(i<mid && j<h)
    {
        if( a[i]>a[j])
        {
            b[k] = a[j];
            j++;
        }
        else
        {
            b[k] = a[i];
            i++;
        }
        k++;
    }

    while(i<mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while(j<h)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    for(int i=0;i<k;i++)
        a[l+i] = b[i];
}

void mergesort(int a[],int l, int h)
{
    if( (h-l) <=1)
        return;

    int mid = l+h;
    mid = mid/2;

    mergesort(a,l,mid);
    mergesort(a,mid,h);

    merge(a,l,mid,h);
}

int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];
    
    mergesort(a,0,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}