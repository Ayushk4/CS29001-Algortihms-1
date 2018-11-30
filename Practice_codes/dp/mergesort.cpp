#include<iostream>
#include<stdlib.h>

using namespace std;



void merge(int a[], int low, int mid, int high)
{
    int l=low, r= mid, i=0;
    int b[high - low];

    while( l<mid && r< high)
    {
        if( a[l] <a[r])
        {
            b[i] = a[l];
            l++;
            i++;
        }
        else
        {
            b[i] = a[r];
            r++;
            i++;
        }        
    }

    while( r<high)
    {
        b[i] = a[r];
        r++;
        i++;
    }
    while( l<mid)
    {
        b[i] = a[l];
        l++;
        i++;
    }


    for(int j=0;j<i;j++)
        a[low+j] = b[j];
}

void mergesort(int a[], int low, int high)
{
    if(  (high -low) <2)
        return ;
    
    int mid = (low + high)/2;

    mergesort(a, low ,mid);
    mergesort(a, mid, high);

    merge (a, low, mid, high);

    return;

}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    mergesort(a,0,n);

    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}