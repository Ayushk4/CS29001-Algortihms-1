#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
    int val, to;
    node * next;
};


struct heap
{
    int * a;
    int size;
};


void siftup(heap *h ,int key[], int da[], int i)
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
            da[h->a[i]] = big;
            da[h->a[big]] = i;

            int tmp = h->a[i];
            h->a[i] = h->a[big];
            h->a[big] = tmp;
            i = big;
    
        }
    }
}

void decreasekey( heap * h, int decrease_to, int key[], int da[], int i)
{
    key[i] = decrease_to;

    siftup(h,key,da,i);
}

void siftdown(heap *h, int key[], int da[], int i)
{
    int n= h->size;

    while( i<n)
    {
        int min = i;
        if( 2*i < n)
        {
            if( key[h->a[min]] >key[h->a[2*i]])
                min = 2*i;
        }
        if ( (2*i+1) < n)
        {
            if( key[h->a[min]] > key[h->a[2*i+1]])
                min = 2*i+1;
        }

        if(min == i)
            break;
        else
        {
            da[h->a[i]] = min;
            da[h->a[min]] = i;

            int tmp = h->a[min];
            h->a[min] = h->a[i];
            h->a[i] = tmp;
            i = min;
        }
    }
}

void buildheap(heap * h, int key[], int da[])
{
    int n= h->size +1;

    for (int i=n-1;i>0;i--)
        siftdown(h,key,da,i);
}

int extractmin(heap *h, int key[], int da[])
{
    int minim = h->a[1];
    da[minim] = -1;

    int n = h->size;
    h->a[1] = h->a[n-1];
    h->size = h->size -1;

    siftdown(h,key,da,1);

    return minim;
}

void insert(node ** a, int from ,int to, int val)
{
    node * ptr = new node;
    ptr->next = a[from];
    a[from] = ptr;
    ptr->val = val;
    ptr->to =to;
}

int main()
{

}