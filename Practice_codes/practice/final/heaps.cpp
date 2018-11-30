#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

void buildheap(int a[], int n)
{
    for(int i=floor(n/2);i>0;i--)
    {
        int j=i,max;
        while(j<n)
        {   max = j;
            if(2*j<n && a[max] <a[2*j])
                max = 2*j;
            if((2*j+1)<n && a[max] <a[2*j+1])
                max = 2*j + 1;

            if( max != j)
            {
                int tmp = a[max];
                a[max] = a[j];
                a[j] = tmp;
                j = max;
            }
            else
                break;
        }
        for(int i=1;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
}

int main()
{
    int n;
    cin>>n;
    n++;

    int *h = new int[n];
    for(int i=1;i<n;i++)
        cin>>h[i];
    
    buildheap(h,n);
}