#include<iostream>

using namespace std;

void swap(int *x,int * y)
{
    int temp = *y;
    *y = *x;
    *x = temp;
}

void sift_up(int a[],int i)
{
    if(i<2)
        return;

    if(a[i]>a[i/2])
        swap(&a[i],&a[i/2]);

    sift_up(a,i/2);
}

void insert(int a[],int i,int val)
{
    a[i] = val;
    sift_up(a,i);
}

void sift_down(int a[],int i, int n)
{
    int large_index = i;;
    if((2*i < n ) && (a[2*i]>a[large_index]))
        large_index = 2*i;
    if((2*i+1 < n ) && (a[2*i+1]>a[large_index]))
        large_index = 2*i+1;
    
    if(large_index == i)
        return;

    swap(&a[large_index],&a[i]);
    sift_down(a,large_index,n);
}

int extract_max(int a[],int *n)
{
    int max = a[1];
    a[1] = a[*n-1];
    
    (*n)--;
    sift_down(a,1,*n);

    return max;
}

int main()
{
    int n;
    cin>>n;
    n++;

    int a[n];
    for(int i=1;i<n;i++)
    {
        int val;
        cin>>val;

        insert(a,i,val);
    }

    //cout<<"\n";
    for(int i=1;i<n;i++)
        cout<<a[i]<< " ";
    
    cout<<"\n"<<extract_max(a,&n);

    cout<<"\n";
    for(int i=1;i<n;i++)
        cout<<a[i]<< " ";

}