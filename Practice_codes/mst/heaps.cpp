#include<iostream>
#include<stdlib.h>

using namespace std;

struct heap
{
    int * a;
    int size;
};

void extractmin(heap *h )
{
    
}

void siftup(heap *h , int i)
{
    while(i>1)
    {
        int big = i;;
        if(h->a[big] < h->a[i/2])
            big = i/2;
        if( i == big )
            break;
        else
        {
            int tmp = h->a[i];
            h->a[i] = h->a[big];
            h->a[big] = tmp;
            i = big;
    
        }
    }
}

void decreasekey( heap * h, int decrease_by, int i)
{
    h->a[i]-=decrease_by;
    siftup(h,i);
}

void siftdown(heap *h, int i)
{
    int n= h->size;

    while( i<n)
    {
        int min = i;
        if( 2*i < n)
        {
            if( h->a[min] >h->a[2*i])
                min = 2*i;
        }
        if ( (2*i+1) < n)
        {
            if( h->a[min] >h->a[2*i+1])
                min = 2*i+1;
        }

        if(min == i)
            break;
        else
        {
            int tmp = h->a[min];
            h->a[min] = h->a[i];
            h->a[i] = tmp;
            i = min;
        }
    }
}

void buildheap(heap * h)
{
    int n= h->size;

    for (int i=n-1;i>0;i--)
        siftdown(h,i);
}


int main()
{
    int hn;
    cin>>hn;

    int a[100];
    heap *h = new heap;
    h->a = a;
    h->size = hn+1;

    for(int i=1;i<=hn;i++)
        cin>>h->a[i];

    buildheap(h);

    for(int i=1;i<h->size;i++)
        cout<<h->a[i]<<" ";

    cout<<h->a[5]<<"\n";
    decreasekey(h,10,5);
    //cout<<h->a[5]<<"\n";
    for(int i=1;i<h->size;i++)
        cout<<h->a[i]<<" ";

}