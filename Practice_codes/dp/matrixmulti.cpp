#include<iostream>
#include<stdlib.h>
using namespace std;

struct dim{
    int l,r;
};

void find_min( dim a[], int n)
{
    int m[n][n],s[n][n];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {   m[i][j] = 0;
            s[i][j] = 0;
        }
    for( int l =1; l<=n;l++ )
        for(int i=0; i<n-l; i++)
        {
            int j = l+i;
            m[i][j] =1000000;
            for(int k=i; k<j; k++)
            {
                int q = m[i][k] + m[k+1][j] + a[i].l * a[k].r * a[j].r;
                if(q<m[i][j])
                {   m[i][j] = q;
                    s[i][j] = k+1;
                }
            }
        }

    for(int i=0; i<n; i++)
    {
        cout<<"\n";
        for(int j=0; j<n; j++)
            cout<<m[i][j]<<"\t";
    }

    cout<<"\n\n";

    for(int i=0; i<n; i++)
    {
        cout<<"\n";
        for(int j=0; j<n; j++)
            cout<<s[i][j]<<" ";
    }
    cout<<"\n\n";
    //return m[n-1][n-1];
}

int main()
{
    int n;
    cin>>n;
    
    dim *a = (dim*)malloc(sizeof(dim)*n);

    for(int i=0;i<n;i++)
        cin>>a[i].l>>a[i].r;


    find_min(a,n);

}