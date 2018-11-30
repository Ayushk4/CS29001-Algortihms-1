#include<iostream>
#include<stdlib.h>

using namespace std;

void dfs_visit(int a[][100], int i, int n, int vis[], int pi[], int d[], int f[], int *time)
{
    *time += 1;

    vis[i] = 1;
    d[i] = *time;
    cout<<i+1<<" ";
    for(int j=0;j<n;j++)
        if(a[i][j] == 1)
            if(vis[j] == 0)
            {
                pi[j] = i;
                dfs_visit(a,j,n,vis,pi,d,f,time);
            }

    *time += 1;

    f[i] = *time;
}

void dfs(int a[][100], int n)
{
    int vis[n], pi[n], d[n], f[n];

    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        pi[i] = -1;
        d[i] = -1;
        f[i] = -1;
    }

    int *time = new int ;
    *time = 0;

    for(int i=0;i<n;i++)
    {
        if(vis[i] == 0)
            dfs_visit(a,i,n,vis,pi,d,f,time);
    }

    for(int i=0;i<n;i++)
        cout<<i+1<<" : "<<pi[i]<<" "<<d[i]<<" "<<f[i]<<"\n";
}

int main()
{
    int n;
    cin>>n;

    int a[n][100];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] = 0;

    int l;
    cin>>l;

    for(int i=0;i<l;i++)
    {
        int from, to;
        cin>>from>>to;
        from--;
        to--;

        a[from][to] = 1;
        a[to][from] = 1;
    }

    dfs(a,n);
}