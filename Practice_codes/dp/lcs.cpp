#include<iostream>

using namespace std;

#define MAX_SIZE 50


void print_lcs(char *x, char *y, int c[][MAX_SIZE], int b[][MAX_SIZE], int n, int m)
{
    if( n<0 || m<0 || c[n][m] == 0 )
        return ;

    if( b[n][m] == 0)
    {
        print_lcs(x,y,c,b,n-1,m-1);
        cout<<x[n];
    }
    else
    {
        if( b[n][m] == 1 )
            print_lcs(x,y,c,b,n-1,m);
        else if( b[n][m] == -1 )
            print_lcs(x,y,c,b,n,m-1);
    }
}


int find_lcs(char *x, char *y, int c [][MAX_SIZE], int b[][MAX_SIZE], int n, int m)
{
    if (n<0 || m<0)
        return 0;

    if( x[n] == y[m] )
    {   c[n][m] = 1 + find_lcs(x,y,c,b,n-1,m-1);
        b[n][m] = 0;
    }

    else
    {
        int p1 = find_lcs(x,y,c,b,n-1,m);
        int p2 = find_lcs(x,y,c,b,n,m-1);

        if(p1>p2)
        {
            c[n][m] = p1;
            b[n][m] = 1;
        }
        else
        {
            c[n][m] = p2;
            b[n][m] = -1;
        
        }
    }
    return c[n][m];
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    char *x,*y;
    x = (char*)malloc(sizeof(char)*n);
    y = (char*)malloc(sizeof(char)*m);

    cin>>x>>y;
    int c[n][MAX_SIZE], b[n][MAX_SIZE];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {   c[i][j] = 0;
            b[i][j] = 1000;
        }

    cout << find_lcs(x,y,c,b,n-1,m-1);
    
    cout<<"\n\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<c[i][j]<<" ";

        cout<<"\n";
    }

    cout<<"\n\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<b[i][j]<<"\t";

        cout<<"\n";
    }

    cout<<"\n";
    print_lcs(x,y,c,b,n-1,m-1);

    return 0;
}