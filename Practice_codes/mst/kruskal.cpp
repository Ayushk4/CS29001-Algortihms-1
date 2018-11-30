#include<iostream>
#include<stdlib.h>

using namespace std;

struct node 
{
    int val,rank;
    node * parent;
};

struct edge
{
    int from, to, val;
};
/*
node * insert(node *root, int val)
{
    node * newptr = new node;
    newptr->left = newptr->right = newptr->parent = NULL;
    newptr->val = val;

    if (root == NULL)
    {
        newptr->root = newptr;
        return newptr;
    }

    newptr->root = root;

    node *prev = NULL, * ptr = root;

    while(ptr!= NULL)
    {
        prev = ptr;
        if( ptr->val > val)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if(prev->val >val)
        prev->left = newptr;
    else
        prev->right = newptr;

    newptr->parent = prev;

    return root;
}
void inorder(node * root, int i=0)
{
    if( root == NULL)
        return;
    i++;

    inorder( root->right,i);
    cout<<root->val<<"\n\n";
    inorder( root->left,i);
}
*/


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


void makeset( node * roots[], node * address[], int i)
{
    node *ptr = new node;
    ptr->parent = ptr;
    ptr->val = i;
    ptr->rank = 0;
    roots[i] = ptr;
    address[i] = ptr;
}

node * findset(node * ptr)
{
//    node * ptr = address[i];

    if( ptr->parent != ptr)
        ptr->parent = findset (ptr->parent);

    return ptr->parent;
}

void unionn(node * a, node * b)
{
    a = findset(a);
    b = findset(b);

    if (a->rank < b->rank)
        a->parent = b;
    else
        b->parent = a;
    if (a->rank == b->rank)
        a->rank = a->rank + 1;
}

void kruskal(edge edges[], int n, int e)
{
    mergesort(edges,0,e);

    node * roots[n+1], *address[n+1];

    for(int i=1;i<=n;i++)
        makeset(roots, address, i);

    int t[100];

    for(int i=0;i<100;i++)
        t[i] = 0;

    for(int i=0;i<e;i++)
    {
        int u = edges[i].from;
        int v = edges[i].to;
        int val = edges[i].val;

        if(findset(address[u]) != findset(address[v]))
        {
            cout<<"a";
            t[i] = 1;
            unionn(address[u],address[v]);
        }
    }

    for(int i=0;i<e;i++)
        if(t[i] == 1)
            cout<<edges[i].from<<" "<<edges[i].to<<" "<<edges[i].val<<"\n";

}


int main()
{
    int e,n;
    cin>>n>>e;

    edge edges[100];

    for(int i=0;i<e;i++)
        cin>>edges[i].from>>edges[i].to>>edges[i].val;
    
//    for(int i=e;i<2*e;i++)
//    {
//        edges[i].from = edges[i-e].from;>>edges[i].to>>edges[i].val;
//    }

    kruskal(edges,n,e);


}