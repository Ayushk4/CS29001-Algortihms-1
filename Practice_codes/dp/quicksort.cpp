#include<iostream>
#include<stdlib.h>

using namespace std;

void swap(int *x, int *y)
{
    int tmp = *y;
    *y = *x;
    *x = tmp;
}

int partition (int a[], int low, int high)
{
    int i = low, piv = low, j = high -1 ;

    while(i<j)
    {
        while( a[i]<=a[piv] && i<j ) i++;
        while( a[j]>a[piv]) j--;

        if( i<j)
        {
            swap( &a[i], & a[j]);
            j--;
        }

    }

    swap( &a[j], &a[piv]);
    
    piv = j;
    return piv;
}

void quicksort(int a[],int low, int high)
{
    if( (high - low)<2)
        return ;
    
    int parti = partition(a,low, high);

    quicksort(a,low, parti);
    quicksort(a,parti+1,high);

    return;
}

int main()
{
    int n;
    cin>>n;

    cout<<n<<"\n";
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    quicksort(a,0, n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<"\n";
}