#include<iostream>

using namespace std;


void merge(int a[],int low, int mid, int high)
{
    int i=low, j= mid, k =0;

    int * tmp = new int [high - low + 1];

    while( i<mid && j<high)
    {
        if( a[i] < a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while( i<mid)
        tmp[k++] = a[i++];
    while( j<high)
        tmp[k++] = a[j++];

    for(int i=0;i<k;i++)
        a[i+low] = tmp[i];
    
}

void sortt(int a[],int low, int high)
{
    if( (high- low) < 2 )
        return;

    int mid = (low+ high) /2;

    sortt(a,low,mid);
    sortt(a,mid,high);

    merge(a,low,mid,high);
}

int zero_present(int a[], int n)
{
    for(int i=0;i<n;i++)
        if(a[i] == 0)
            return 1;
    
    return 0;
}

int main()
{
    int n;
    cin>>n;

    int * a = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int prod = 1, last_odd =0, no_multi = 0;

    sortt(a,0,n);

    for(int i=0;i<n;i++)
    {
        if( a[i]>0)
        {    
            prod *= a[i];
            no_multi++;
        }
    }

//    for(int i=0;i<n;i++)
//        cout<<a[i]<<" ";

    for(int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            if( last_odd != 0)
            {
                prod *= last_odd * a[i];
                last_odd = 0;
                no_multi++;
            }
            else
            {
                last_odd = a[i];
            }
        }
    }

    if( no_multi == 0)
    {
        if(zero_present(a,n) == 1)
            prod = 0;
        else
            prod = a[0];

    }

    cout<<prod<<"\n";
}