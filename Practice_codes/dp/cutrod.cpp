#include<iostream>
#include<stdlib.h>
using namespace std;


int max_im(int x, int y)
{
    if( x >= y)
        return x;
    else
        return y;
}

int bottom_up(int *a, int *b, int * s,int n)
{
    int var;
    for(int i=1; i<n; i++)
    {
        var = -1;
        for(int j= 0; j<i; j++)
        {   int k =(a[i-j] + b[j]);
            if(var<k)
            {
                var = k;
                s[i] = j;
            }
        }
        b[i] = var;
    }
    return b[n-1];
}

int dp_aprroach_top_down(int *a,int *b,int n)
{

    int j = -1;
    for(int i=n-1; i>0; i--)
    {
       j = max_im(j, (a[n-i] + dp_aprroach_top_down(a,b, i)) );
    }
    b[n-1] = j;
    return j;
}

int find_max(int *a,int n)
{
    int *b;
    b = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
        b[i] = 0;

    int s[n];
    cout<<"\n";
    int max = bottom_up(a,b,n);
    for(int i=1;i<n;i++)
        cout<<b[i]<<" ";
    return max;
}

int main()
{
    int n;
    cin>>n;
    n++;

    int * a;
    a = (int *)malloc(sizeof(int)*n);

    for(int i=1;i<n;i++)
        cin>>a[i];

    int max =find_max(a,n);
    cout<<"\n";
    cout<<max;



    free(a);
}