#include<iostream>
#include<stdlib.h>

using namespace std;

int partition(int a[], int low, int high)
{
    int i=low, j=high, piv =low;

    while(i< j)
    {
        while(i<high && a[i]<=a[piv]) i++;
        while(a[j]>a[piv]) j--;

        if( i<j)
        {
            int tmp = a[j];
            a[j] = a[i];
            a[i] = tmp;
            j--;
        }
    }

    int tmp = a[piv];
    a[piv] = a[j];
    a[j] = tmp;
    return j;
}

void quicksort(int a[],int low, int high)
{
    if( (high - low) <=1)
        return;

    int parti = partition(a,low,high);

    quicksort(a,low,parti);
    quicksort(a,parti + 1,high);
}

int main()
{
    int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,0,n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}