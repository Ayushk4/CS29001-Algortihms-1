#include<iostream>
#include<stdlib.h>

using namespace std;
#define MAX_SIZE 100
struct pt{
    int val,parent;
};


void print_lcs(char * x, char * y, pt c [] [MAX_SIZE], int i, int j)
{
    if( i<0 || j<0)
        return;

    if( c[i][j].parent == 0)
    {
        print_lcs(x,y,c,i-1,j-1);
        cout<<x[i];
    }
    else
    {
        if( c[i][j].parent == -1)
            print_lcs(x,y,c,i,j-1);
        else
            if( c[i][j].parent == 1)
                print_lcs(x,y,c,i-1,j);
    }

}

int lcs(char * x, char * y, pt c[][MAX_SIZE], int i, int j)
{
    if( i<0 || j<0 )
        return 0;
    
    if( c[i][j].val >0)
        return c[i][j].val;
    
    if( x[i] == y[j])
    {
        c[i][j].parent = 0;
        c[i][j].val = (1 + lcs(x,y,c,i-1,j-1) );
    }
    else
    {
        int p = lcs(x,y,c,i,j-1);
        int q = lcs(x,y,c,i-1,j);

        if( p>q)
        {
            c[i][j].parent = -1;
            c[i][j].val = p;
        }
        else
        {
            c[i][j].parent = 1;
            c[i][j].val = q;
        }
    }

    return c[i][j].val;

}


int main()
{
    int n,m;
    cin>>n>>m;

    char *x, *y;
    x =(char*) malloc(sizeof(char) * n);
    y = (char*)malloc(sizeof(char) * m);
    cin>>x>>y;
    //cout<<x<<y;

    pt c[n][MAX_SIZE];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            c[i][j].val = 0;
            c[i][j].parent = 1000;
        }

    cout<< lcs (x,y,c,n-1,m-1);


/*
    cout<<"\n\n\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<c[i][j].val<<"\t";
        
        cout<<"\n";
    }


    cout<<"\n\n";
    for(int i=0;i<n;i++)
    {
        for( int j=0;j<m;j++)
            cout<<c[i][j].parent<<"\t";

        cout<<"\n";

    }
*/
    cout<<" ";
    print_lcs(x,y,c,n-1,m-1);
    cout<<"\n";

}