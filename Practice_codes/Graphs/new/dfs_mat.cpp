#include<iostream>
#include<stdlib.h>

using namespace std;


void dfs_visit( int a[][100], int i, int n, int vis[], int pi[], int d[], int f[])
{
    cout<<i+1<<" ";
    for(int j=0;j<n;j++)
    {
        if(a[i][j] == 1 )
            if(vis[j] == 0)
            {
                pi[j] = i;
                vis[j] = 1;
                dfs_visit(a,j,n,vis,pi,d,f);
            }
    }
}


void dfs(int a[][100], int n)
{
    int vis[n], pi[n], d[n], f[n];

    for(int i=0;i<n;i++)
    {   vis[i] = 0;
        pi[n] = -1;
        d[n] = 0;
        f[n] = 0;
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
        from--;to--;

        a[from][to] = 1;
        a[to][from] = 1;
    }

    dfs(a,n);
}