#include<iostream>

using namespace std;

int main()
{
    int m,n;
    cin>>n>>m;

    int i, a[n],c[m];

    for(i=0;i<m;i++)
        c[i] = 0;

    for(i=0;i<n;i++)
    {   cin>>a[i];
        c[a[i]]++;
    }

    c[0]--;
    for(i=1;i<m;i++)
        c[i] = c[i] + c[i-1];
    
    int b[n];
    cout<<"\n";

    for(i=0;i<n;i++)
        b[c[a[i]]--] = a[i];

    for(i =0;i< n;i++)
        cout<<b[i]<<" ";

    return 0;
}
