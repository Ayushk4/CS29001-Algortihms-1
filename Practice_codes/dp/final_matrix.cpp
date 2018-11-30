#include<iostream>
#include<stdlib.h>

using namespace std;
#define MAX_SIZE 100

struct dim {
    int l,r;
};

int min__(int x, int y)
{
    if (x>y)
        return y;

    return x;    
}

int find_mat(dim a[],int m[][MAX_SIZE],int n)
{
    if(n<=0)
        return 0;
    
    for(int l = 1;l<n;l++)
        
        for(int i=0;i<n-l;i++)
        {
            int j =i+l;
            m[i][j] =100000000;
            for(int k=i;k<j;k++)
                m[i][j] = min__( m[i][j] , m[i][k] + m[k+1][j] + a[i].l * a[k].r * a[j].r );
        }

    return m[0][n-1];
}


int main()
{
    int n;
    cin>>n;

    int m[n][MAX_SIZE];
    dim a[n];

    for(int i=0;i<n;i++)
        cin>>a[i].l>>a[i].r;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            m[i][j] = 0;
    }

    int max = find_mat(a,m,n);

    cout<<"\n\n";

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<m[i][j]<<"\t";

        cout<<"\n";
    }
}