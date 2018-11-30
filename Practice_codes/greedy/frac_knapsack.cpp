#include<iostream>
#include<stdlib.h>

using namespace std;

struct item{
    int weight,value;
};


void merge(item obj[], int low, int mid, int high)
{
    int i=low, j=mid,  k=0;;
    item tmp[high-low+1];

    while(i<mid &&j<high)
    {
        if( (float(obj[i].weight)/obj[i].value) < (float(obj[j].weight)/obj[j].value) )
            tmp[k++] = obj[i++];
        else
            tmp[k++] = obj[j++];
    }

    while(i<mid)
    {
        tmp[k++] = obj[i++];
    }

    while(j<high)
    {
        tmp[k++] = obj[j++];
    }

    for(int i=0;i<k;i++)
        obj[low+i] = tmp[i];
}

void sort_wbyv(item obj[],int low, int high)
{
    if(low>=high)
        return;

    int mid = (low + high)/2;

    sort_wbyv(obj,low,mid);
    sort_wbyv(obj,mid+1,high);

    merge(obj,low,mid,high);
}

int main()
{
    int n,capacity;
    cin>>n>>capacity;

    item obj[n];

    for(int i=0;i<n;i++)
        cin>>obj[i].weight>>obj[i].value;

    sort_wbyv(obj,0,n);

    for(int i=0;i<n;i++)
        cout<<obj[i].weight<<" "<<obj[i].value<<"\n";

    float price = 0;
    cout<<"\n";
    int i=0;
    while(capacity>0 && i<n)
    {
        if( obj[i].weight<capacity)
        {
            capacity-=obj[i].weight;
            price += obj[i].value;
        }
        else
        {
            price += (float(obj[i].value)/float(obj[i].weight))*capacity;
            capacity = 0;
        }
        i++;
    }

    cout<<price<<" "<<i<<"\n";
}