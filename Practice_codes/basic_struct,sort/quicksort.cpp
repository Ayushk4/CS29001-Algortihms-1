#include<iostream>

using namespace std;

void swap(int *x,int*y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition(int a[],int l,int h)
{
    int i=l, j= h, pivot = l;

    while(i<j)
    {
        while(a[i]<=a[pivot] &&i<h)i++;
        while(a[j]>a[pivot])j--;
        if( i<j)
        {   swap(&a[i],&a[j]);
            j--;
        }
    }

    swap(&a[pivot], &a[j]);
    return j;
}

void quicksort(int a[],int l,int h)
{
    if((h-l)<=1)
        return ;
    
    int parti = partition(a,l,h);

    quicksort(a,l,parti);
    quicksort(a,parti+1,h);

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
    cout<<"\n";
}