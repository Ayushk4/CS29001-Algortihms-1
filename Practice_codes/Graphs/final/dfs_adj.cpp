#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
    int from, to;
    node * next;
};

struct adj{
    node * next;
};

void dfs_visit(adj a[],int i, int n, int vis[], int pi[], int d[], int f[], int *time)
{
    *time = *time + 1;
    d[i] = *time;
    vis[i] = 1;
    //cout<<i+1<<" ";
    node * ptr = a[i].next;

    while(ptr!= NULL)
    {
        int j = ptr->to;
        if(vis[j] == 0)
        {
            pi[j] = i+1;
            cout<<"tree"<<i<<","<<j<<"\n";
            dfs_visit(a,j,n,vis,pi,d,f,time);
        }
        if(vis[j] == 1)
        {
            if( f[i] <0)
                cout<<"back"<<i<<","<<j<<"\n";
            else
                if( d[i]>d[j])
                    cout<<"cross"<<i<<","<<j<<"\n";
        }
        ptr= ptr->next;
    }

    *time = *time + 1;
    f[i] = *time;
}

void dfs(adj a[], int n)
{
    int vis[n],pi[n], f[n], d[n];
    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        pi[i] = -1;
        d[i] = -1;
        f[i] = -1;
    }

    int *time = new int;
    *time = 0;

    for(int i=0;i<n;i++)
    {
        if(vis[i] == 0)
        {
            vis[i] = 1;
            dfs_visit(a,i,n,vis,pi,d,f,time);
        }
    }

}

void insert(adj a[],int from, int to)
{
    node * ptr = new node;
    ptr->from = from;
    ptr->to = to;
    ptr->next = a[from].next;

    a[from].next = ptr;
}

int main()
{

    int n,s,l;
    cin>>n>>s>>l;

    adj * a = new adj[n];

    for(int i=0;i<n;i++)
        a[i].next = NULL;

    for(int i=0;i<l;i++)
    {
        int from, to;
        cin>>from>>to;
        from--; to--;

        insert(a,from,to);
        insert(a,to,from);
    }
/*
    for(int i=0;i<n;i++)
    {
        node * ptr = a[i].next;
        cout<<"\n"<<i+1<<" : ";
        while(ptr!= NULL)
        {
            cout<<ptr->to+1<<" ";
            ptr = ptr->next;
        }
    }
    cout<<"\n\n\n\n";
*/
    dfs(a,n);
    cout<<"\n";
}