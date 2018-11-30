#include<iostream>

using namespace std;

void swap(int *x,int * y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

void max_heapify(int a[],int i, int n)
{
    int large_index = i;
    if( (2* i <n) && (a[2*i]>a[large_index]))
        large_index = 2*i;
    if( (2*i+1<n) && (a[2*i+1]>a[large_index]))
        large_index = 2*i+1;

    if( large_index == i )
        return;
    
    swap(&a[i],&a[large_index]);
    max_heapify(a,large_index,n);
}

void build_maxheap(int a[], int n)
{
    for(int i= n/2;i>0;i--)
    {    max_heapify(a,i,n);
    }

}

int main()
{
    int n;
    cin>>n;
    n++;

    int a[n];

    for(int i =1;i<n;i++)
    {
        cin>>a[i];   
    }

    build_maxheap(a,n);

    //cout<<"\n";
    for(int i=1;i<n;i++)
        cout<<a[i]<< " ";
}