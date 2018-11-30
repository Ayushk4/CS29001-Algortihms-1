#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int v,n; //no of nodes
    cin>>v;

    n = v;

    int **a = (int **) malloc(sizeof(int*) * n);

    for(int i=0;i<n;i++)
        a[i] = (int *) malloc (sizeof (int) * n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            a[i][j] = 0;

    int l; //edge
    cin>>l;
    for (int i=0;i<l;i++)
    {
        int from, to;
        cin>>from>>to;
        
        a[from-1][to-1] = 1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
}