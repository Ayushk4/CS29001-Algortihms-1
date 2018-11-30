#include<iostream>
#include<stdlib.h>

using namespace std;

struct job{
    int id,deadline,profit;
};

void mergep(job a[],int l,int mid, int h)
{
    int i = l, j = mid, k=0;
    job b[h-l];

    while(i<mid && j<h)
    {
        if( a[i].profit<a[j].profit)
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


void sortp(job a[], int low,int high)
{
    if( (high - low) <=1)
        return;

    int mid = (high + low)/2;

    sortp(a,low,mid);
    sortp(a,mid,high);
    mergep(a,low,mid,high);
}

void merged(job a[],int l,int mid, int h)
{
    int i = l, j = mid, k=0;
    job b[h-l];

    while(i<mid && j<h)
    {
        if( a[i].deadline>a[j].deadline)
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


void sortd(job a[], int low, int high)
{
    if( (high - low) <=1)
        return;

    int mid = (high + low)/2;

    sortd(a,low,mid);
    sortd(a,mid,high);
    merged(a,low,mid,high);
}



int main()
{
    int n;
    cin>>n;

    job a[n];

    for(int i=0;i<n;i++)
    {
        a[i].id = i+1;
        cin>>a[i].deadline; 
        cin>>a[i].profit;
    }

    sortp(a,0,n);
    sortd(a,0,n);

   /* for(int i=0;i<n;i++)
    {
        cout<<a[i].id<<" "<<a[i].deadline<<" "<<a[i].profit<<"\n";
    }
*/
    int time = 0;
    for(int i=0;i<n;i++)
        if(time<a[i].deadline)
        {
            cout<<a[i].id<<" ";
            time ++;
        }
    cout<<"\n";
}