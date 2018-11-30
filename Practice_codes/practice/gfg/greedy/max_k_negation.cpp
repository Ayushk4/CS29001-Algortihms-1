#include<iostream>
#include<math.h>

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


int main()
{
    int n;
    cin>>n;

    int * a = new int [n];

    int neg = 0;
    for(int i=0;i<n;i++)
        cin>>a[i];

    int k;
    cin>>k;

    for(int i=0;i<n;i++)
        if(a[i]<0)
            neg++;

fdghjzdfghjnkmlghjkl;   not complete rdtfhyujiklrdtfyghujk;
    if((neg - k)%2 == 0)
    {
        sortt(a,0,n);

        for(int i=0;i<k;i++)
            a[i] = -1* a[i];

    }
    else
    {
        for(int i=0;i<neg;i++)
            a[i] = -1* a[i];

        int min = 0;
        for(int i=1;i<n;i++)
            if(a[i] < min)
                min = i;
        
        a[min] = -1 * a[min];
    }
    


    int sum = 0;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    //    sum += a[i];

    cout<<sum<<"\n";
    free(a);
}