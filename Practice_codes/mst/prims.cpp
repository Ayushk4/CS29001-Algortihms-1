#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int weight;
    int to;
    node* next;
};

struct adjlist
{
    node * first;
};

struct heap
{
    int * a;
    int size;
};

void siftup(heap *h ,int da[], int key[], int i)
{
    while(i>1)
    {
        int big = i;
        if(key[h->a[big]] < key[h->a[i/2]])
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
void decreasekey( heap * h, int decrease_to, int da[], int key[], int i)
{
    key[i] = decrease_to;
    siftup(h,da,key,da[i]);
}

void siftdown(heap *h, int key[], int da[], int i)
{
    int n= h->size-1;

    while( i<n)
    {
        int min = i;
        if( 2*i <=n)
        {
            if( key[h->a[min]] > key[h->a[2*i]])
                min = 2*i;
        }
        if ( (2*i+1) <= n)
        {
            if( key[h->a[min]] >key[h->a[2*i+1]])
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
    int n= h->size;

    for (int i=n-1;i>0;i--)
        siftdown(h,key,da,i);
}

int extractmin(heap * h, int key[],int da[])
{
    int minim = h->a[1];
    h->size = h->size -1;
    da[minim] = -1;
    h->a[1] = h->a[h->size];
    da[h->a[1]] = 1;

    siftdown(h,key,da,1);

    return minim;
}

void prims(adjlist a[], int n, int e)
{
    int key[n+1], pi[n+1], da[n+1];

    for(int i=1;i<=n;i++)
    {
        key[i] = 10000;
        pi[i] = -1;
    }
    heap * h = new heap;
    h->a = new int[n+1];
    h->size = n+1;

    for(int i=1;i<=n;i++)
    {   
        h->a[i] = i;
        da[i] =i;
    }
    key[1] = 0;
    buildheap(h,key,da);

    while(h->size>1)
    {
        int u = extractmin(h,key,da);
        node * ptr = a[u].first;

        while(ptr!= NULL)
        {
            if(da[ptr->to] != -1 && key[ptr->to] > ptr->weight)
            {
                decreasekey(h,ptr->weight, da, key, ptr->to);
                pi[ptr->to] = u;
            }
            ptr = ptr->next;

        }

    }
/*
cout<<" ";
    for(int i=1;i<=n;i++)
        cout<<key[i]<<" ";
*/
cout<<"\n";
    for(int i=1;i<=n;i++)
        cout<<pi[i]<<" "<<i<<"\n";
/*
cout<<"\n ";
    for(int i=1;i<=n;i++)
        cout<<i<<" ";
*/
}

void insrt( adjlist a[], int from, int to, int weight)
{
    node * ptr = new node ;
    ptr->to = to;
    ptr->weight = weight;
    ptr->next = a[from].first;
    a[from].first = ptr;
}



int main()
{
    int n, e;
    cin>>n>>e;

    adjlist *a = new adjlist[n+1];

    for(int i=0;i<e;i++)
    {   
        int from, to, weight;
        cin>>from>>to>>weight; 
        //from--;
        //to--;
        insrt(a,from, to, weight);
        insrt(a,to,from,weight);
    }
/*
    for(int i=0;i<n;i++)
    {
        node * ptr = a[i].first;

        while( ptr != NULL)
        {
            cout<<i+1<<" "<<ptr->to+1<<" "<<ptr->weight<<"\n";
            ptr = ptr->next;
        }
    }
*/
    prims(a,n,e);
}
