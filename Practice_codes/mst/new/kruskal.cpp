#include<iostream>
#include<stdlib.h>

using namespace std;

struct edge
{
    int from,to,val;
};

struct node 
{
    int rank;
    node *parent;
};


void merge(edge a[], int low, int mid, int high)
{
    int l=low, r= mid, i=0;
    edge b[high - low];

    while( l<mid && r< high)
    {
        if( a[l].val <a[r].val)
        {
            b[i] = a[l];
            l++;
            i++;
        }
        else
        {
            b[i] = a[r];
            r++;
            i++;
        }        
    }
    while( r<high)
    {
        b[i] = a[r];
        r++;
        i++;
    }
    while( l<mid)
    {
        b[i] = a[l];
        l++;
        i++;
    }
    for(int j=0;j<i;j++)
        a[low+j] = b[j];
}
void mergesort(edge a[], int low, int high)
{
    if(  (high -low) <2)
        return ;
    int mid = (low + high)/2;
    mergesort(a, low ,mid);
    mergesort(a, mid, high);
    merge (a, low, mid, high);
    return;
}


node * makeroot()
{
    node * ptr = new node;
    ptr->parent = ptr;
    ptr->rank = 0;

    return ptr;
}

node * findset(node * ptr)
{
    if( ptr->parent != ptr)
        ptr->parent = findset(ptr->parent);
    
    return ptr->parent;
}

void unionn(node * a, node *b)
{
    a = findset(a);
    b = findset(b);
    if(a->rank < b->rank)
        a->parent = b;
    else
        b->parent = a;
    
    if( a->rank == b->rank)
        a->rank = a->rank + 1;

}

void kruskals(edge edges[], int n, int e)
{
    mergesort(edges,0,e);

    int t[e];
    for (int i=0;i<e;i++)
        t[i] = 0;

    node * add[n];
    for(int i=1;i<=n;i++)
        add[i] = makeroot();

    for(int i=0;i<e;i++)
    {
        int u = edges[i].from;
        int v = edges[i].to;

        if(findset(add[u]) != findset(add[v]))
        {
            t[i] = 1;
            unionn(add[u], add[v]);
        }

        //cout<<edges[i].from<<" "<<edges[i].to<<" "<<edges[i].val<<"\n";
    }

    for(int i=0;i<e;i++)
        //cout<<t[i]<<" ";
        if(t[i] == 1)
            cout<<edges[i].from<<" "<<edges[i].to<<" "<<edges[i].val<<"\n";

    cout<<"\n";

    cout<<"\n";
}

int main()
{
    int n,e;
    cin>>n>>e;

    edge edges [e];
    for(int i=0;i<e;i++)
        cin>>edges[i].from>>edges[i].to>>edges[i].val;

    kruskals(edges,n,e);

    for(int i=0;i<e;i++)
        cout<<edges[i].from<<" "<<edges[i].to<<" "<<edges[i].val<<"\n";
}