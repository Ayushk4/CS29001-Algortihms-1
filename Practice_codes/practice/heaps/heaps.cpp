//build heap
//insert into heap
//sift up
//sift down
//decrease key
//increase key
//extract min
//find min

#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

void sift_down(int a[], int i, int n)
{
    int j = i;
    //cout<<"a"<<a[i];

    while( j<n)
    {
        int max = i;

        if(2*i < n && a[max] < a[2*i])
            max = 2*i;
        if ((2*i+1) < n && a[max] < a[2*i+1])
            max = 2*i+1;

        if( max != i)
        {
            int tmp = a[max];
            a[max] = a[i];
            a[i] = tmp;
            i =max;
        }
        else
        {
            break;
        }
    }
}

void build_heap(int a[], int n)
{
    for(int i=ceil(n/2);i>0;i--)
        sift_down(a,i,n);
}

void sift_down(int a[],int i )
{
    int j = i;
    while( j>1)
    {
        if( a[j] > a[int(floor(j/2))])
        {
            int tmp = a[j];
            a[j] = a[int(floor(j/2))];
            a[int(floor(j/2))] = tmp;
            j = int(floor(j/2));
        }
        else
            break;
    }
}

void insert(int a[],int i, int val)
{
    a[i] = val;
    sift_down(a,i);
}
int main()
{
    int n;
    cin>>n;
    n++;

    int *a = new int[n];

    for(int i=1;i<n;i++)
    {    
        int val;
        cin>>val;
        insert(a,i,val);    
    }
    //build_heap(a,n);

    for(int i=1;i<n;i++)
        cout<<a[i]<<" ";

}