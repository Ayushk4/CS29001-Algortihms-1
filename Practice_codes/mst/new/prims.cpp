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

void prims(node ** adjlist, int n, int e)
{
    int key[n+1],pi[n+1],da[n+1], a[n+1];
    heap *h = new heap;
    h->a = a;
    h->size = n+1;
    for(int i=1;i<=n;i++)
    {
        key[i] = 10000;
        pi[i] = -1;
        da[i] = i;
        h->a[i] = i;
    }

    key[1] = 0;
    buildheap(h,key,da);

    while(h->size>1)
    {
        int u = extractmin(h,key,da);

        node * ptr = adjlist[u];

        while(ptr!= NULL)
        {
            int v = ptr->to;

            if(da[v] != -1 && key[v] > ptr->val)
            {
                decreasekey(h,ptr->val, key, da,v);
                pi[v] = u;
            }
            ptr = ptr->next;
        }
    }

    for(int i=1;i<=n;i++)
        cout<<pi[i]<<" ";

    cout<<"\n";
    
    for(int i=1;i<=n;i++)
        cout<<i<<" ";

    cout<<"\n";
    
    for(int i=1;i<=n;i++)
        cout<<key[i]<<" ";    
}

int main()
{
    int n,e;
    cin>>n>>e;

    node **adjlist = new node*[n+1];

    for(int i=1;i<=n;i++)
        adjlist[i] = NULL;

    for(int i=0;i<e;i++)
    {
        int from, to, val;
        cin>>from>>to>>val;
        insert(adjlist, from, to, val);
        insert(adjlist, to, from, val);
    }

    for(int i=0;i<n;i++)
    {
        node * ptr = adjlist[i];

        while(ptr != NULL)
        {
            cout<<i<<" "<<ptr->to<<" "<<ptr->val<<"\n";
            ptr = ptr->next;
        }
    }

    prims(adjlist, n, e);
}


// input edges
// make min heap
// for heap not empty
//      u = extractmin 
//      for all the edges orginating from u
//          if edge v not in heap 
//              if v[key] is greater than new edge weight
//                  change v[key] and decreasekey
//                  pi[v] = u;
// Answer is edges(u,pi[u])