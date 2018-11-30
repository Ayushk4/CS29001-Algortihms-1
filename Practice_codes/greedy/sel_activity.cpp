#include<iostream>
#include<stdlib.h>

using namespace std;


struct job{
    int start, end;
};

void sorted_merge(job a[], int low, int mid, int high)
{
    int i=low, j = mid, k=0;
    job tmp[high-low+1];

    while(i<mid && j<high)
    {
        if( a[i].end < a[j].end) 
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    while(i<mid)
        tmp[k++] = a[i++];

    while(j<high)
        tmp[k++] = a[j++];
    
    for(i=0;i<k;i++)
        a[low+i] = tmp[i];
    
    return;
}

void msort(job a[],int low, int high)
{
    if( (high- low) <=1)
        return;

    int mid =(low+high)/2;

    msort(a,low,mid);
    msort(a,mid,high);

    sorted_merge(a,low,mid,high);
}

int main()
{
    int n;
    cin>>n;
    
    job a[n];

    for(int i=0;i<n;i++)
        cin>>a[i].start>>a[i].end;

    msort(a,0,n);

    int time = 0, job_count = 0, i = 0;

    while(i<n)
    {
        while(i<n && a[i].start < time)
            i++;
        time = a[i].end;
        i++;
        job_count++;
    }

    cout<<job_count<<"\n";
}