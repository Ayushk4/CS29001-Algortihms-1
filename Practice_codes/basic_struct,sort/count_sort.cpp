#include<iostream>
using namespace std;

void count_sort(int a[],int n,int k)
{
    int c[k];
    c[0]=-1;
    for(int i=1;i<k;i++)
        c[i] =0;

    for(int i=0;i<n;i++)
        c[a[i]]++;

    for(int i=1;i<k;i++)
        c[i] = c[i]+c[i-1];

    int b[n];

    for(int i=n-1;i>=0;i--)
    {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }

    for(int i=0;i<n;i++)
        a[i] =b[i];
}

int main()
{
    int n,k;
    cin>>n>>k;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    count_sort(a,n,k);

    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}