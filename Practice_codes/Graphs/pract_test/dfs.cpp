#include<iostream>
#include<stdlib.h>

using namespace std;

void dfs_vis(int i, int n, int m[][100], int vis[], int pi[], int d[], int f[], int *tim)
{
    *tim = *tim +1;
    vis[i] = 1;
    d[i] = *tim;
    for(int j=0;j<n;j++)
    {
        if(m[i][j] == 1)
            if( vis[j] == 0)
            {
                pi[j] = i;
                dfs_vis(j,n,m,vis,pi,d,f,tim);
            }
    }

    *tim = *tim +1;
    f[i] = *tim;

}

void dfs(int n, int m[][100])
{
    int vis[n], pi[n], d[n], f[n];

    for(int i=0;i<n;i++)
    {
        vis[i] = 0;
        pi[i] = -1;
        d[i] = 0;
        f[i] = 0;
    }

    int *tim =new int;
    *tim = 0;

    for(int i=0;i<n;i++)
        if(vis[i] == 0)
            dfs_vis(i,n,m,vis,pi,d,f,tim);

    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<vis[i]<<" ";

    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<pi[i]<<" ";

    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<d[i]<<" ";

    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<f[i]<<" ";
}

int main()
{
    int n,s,e;

    cin>>n>>s>>e;

    int m[n][100];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            m[i][j] = 0;

    for(int i=0;i<e;i++)
    {
        int from,to;
        cin>>from>>to;
        from--;to--;

        m[from][to] = 1;
    }

    dfs(n,m);

}