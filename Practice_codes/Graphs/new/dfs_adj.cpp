#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int from;
    int to;
    node * next;
};

struct adj_list
{
    node * next;
};

void dfs_visit( adj_list a[], int i, int n, int vis[], int pi[], int d[], int f[])
{
    cout<<i+1<<" ";

    node * ptr = a[i].next;
    while(ptr != NULL)
    {
        if(vis[ptr->to] == 0)
        {
            pi[ptr->to] = i;
            vis[ptr->to] = 1;
            dfs_visit(a,ptr->to,n,vis,pi,d,f);
            //cout<<ptr->to<<" ";
        }
        ptr = ptr->next;
    }
}


void dfs(adj_list a[], int n)
{
    int vis[n], pi[n], d[n], f[n];

    for(int i=0;i<n;i++)
    {   vis[i] = 0;
        pi[i] = -1;
        d[i] = 0;
        f[i] = 0;
    }
    int time = 0;

    for(int i=0;i<n;i++)
    {
        if( vis[i] == 0)
        {
            vis[i] = 1;
            dfs_visit(a,i,n,vis,pi,d,f);

        }
    }
}

void insrt_adj_list( adj_list a[], int from, int to)
{
    node * new_ptr = new node;
    new_ptr->from = from;
    new_ptr->to = to;
    new_ptr->next = a[from].next;

    a[from].next = new_ptr;

}

int main()
{
    int n;
    cin>>n;

    adj_list * a = (adj_list *) malloc(sizeof(adj_list) * n);

    for(int i=0;i<n;i++)
        a[i].next = NULL;

    int l;
    cin>>l;

    for(int i=0;i<l;i++)
    {
        int from, to;
        cin>>from>>to;
        from--;to--;

        insrt_adj_list(a,from,to);
        insrt_adj_list(a,to,from);
    }

/*    for(int i=0;i<n;i++)
    {
        node * ptr = a[i].next;
        cout<<i+1<<" : ";

        while(ptr!= NULL)
        {
            cout<<ptr-> to <<"," <<ptr->from<<" ";
            ptr= ptr->next;
        }
        cout<<"\n";
    }
*/
    dfs(a,n);
}