#include<iostream>

using namespace std;

void swap(int *x,int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void max_heapify(int a[],int i,int n)
{
    int large_index = i;

    if((2*i < n)&&(a[2*i]>a[i]))
        large_index = 2*i;
    if(((2*i+1)< n)&&(a[2*i + 1]>a[large_index]))
        large_index = 2*i + 1;

    if( large_index == i)
        return;

    swap(&a[i],&a[large_index]);
    max_heapify(a,large_index,n);
}

void build_max_heap(int a[],int n)
{
    int i;
    for(i = n/2;i>0;i--)
    {
        cout<<"\n";
        cout<<a[i]<<" \t ";
        max_heapify(a,i,n);
        for(int j=1;j<n;j++)
            cout<<a[j]<<" ";
    }

     /*   i++;
        
        cout<<"\nsaf";
        cout<<a[i]<<" \t ";
        max_heapify(a,i,n);
        for(int j=1;j<n;j++)
            cout<<a[j]<<" ";
    
*/
}

int main()
{
    int n;
    cin>>n;
    n++;
    int a[n];

    a[0] =0;
    for(int i=1;i<n;i++)
    {
        int val;
        cin>>val;
        a[i] = val;
    }

    build_max_heap(a,n);

    cout<<"\n\n\n\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    max_heapify(a,1,n);
    cout<<"\n";
}
