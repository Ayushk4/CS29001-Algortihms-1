#include<iostream>

using namespace std;
//Max - heap

void swap(int *x,int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void sift_up(int a[],int i)
{
    if(i==1)
        return;
    if(a[i]>a[i/2])
    {
        swap(&a[i],&a[i/2]);
        sift_up(a,i/2);
    }
    return;
}

void sift_down(int a[],int i, int n)
{
    int large_index = i;;
    if((2*i < n ) && (a[2*i]>a[large_index]))
        large_index = 2*i;
    if((2*i+1 < n ) && (a[2*i+1]>a[large_index]))
        large_index = 2*i+1;
    
    if(large_index == i)
        return;

    swap(&a[large_index],&a[i]);
    sift_down(a,large_index,n);
}

int extract_max(int a[],int *n)
{
    int max = a[1];

    a[1] = a[*n-1];
    (*n)--;
    sift_down(a,1,*n);
    return max;
}

int main()
{
    int i,n;
    cin>>n;
    n++;

    int a[n];

    for(int i=1;i<n;i++)
    {
        cin>>a[i];
        sift_up(a,i);
    }

    cout<<"\n";
    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";
}